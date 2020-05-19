// Emacs style mode select   -*- C++ -*- 
//-----------------------------------------------------------------------------
//
// $Id: p_extnodes.c,v 1.1 2020/05/19 11:20:16 micha Exp $
//
//  Copyright (C) 1999 by
//  id Software, Chi Hoang, Lee Killough, Jim Flynn, Rand Phares, Ty Halderman
//  Copyright(C) 2015-2020 Fabian Greffrath
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 
//  02111-1307, USA.
//
//  DESCRIPTION:
//  Support maps with NODES in compressed or uncompressed ZDBSP format or
//  DeePBSP format.
//
//-----------------------------------------------------------------------------

// [MB] 2020-04-21: Support for ZDoom extended nodes based on woof 1.2.0
//      Modified to use C99 fixed width data types
//      Added some checks taken from DooM Legacy code for regular nodes
//      Fixed endianess and use LE_SWAP* macros
//      Added #ifdef switches for all code that requires zlib

// [FG] support maps with NODES in compressed ZDBSP format
#ifdef HAVE_ZLIB
#include <string.h>  // [MB] 2020-05-19: For memcpy()
#include <zlib.h>
#endif  // HAVE_ZLIB

#include "doomincl.h"

#include "m_swap.h"
#include "r_main.h"
#include "r_splats.h"  // [MB] 2020-04-21: Added for hardware renderer
#include "w_wad.h"
#include "z_zone.h"

#include "p_extnodes.h"

// [crispy] support maps with NODES in DeePBSP format

typedef PACKED_STRUCT (
{
    int32_t v1;
    int32_t v2;
    uint16_t angle;
    uint16_t linedef;
    int16_t side;
    uint16_t offset;
}) mapseg_deepbsp_t;

typedef PACKED_STRUCT (
{
    int16_t x;
    int16_t y;
    int16_t dx;
    int16_t dy;
    int16_t bbox[2][4];
    int32_t children[2];
}) mapnode_deepbsp_t;

typedef PACKED_STRUCT (
{
    uint16_t numsegs;
    int32_t firstseg;
}) mapsubsector_deepbsp_t;

// [crispy] support maps with NODES in ZDBSP format

typedef PACKED_STRUCT (
{
    int32_t v1, v2;
    uint16_t linedef;
    unsigned char side;
}) mapseg_zdbsp_t;

typedef PACKED_STRUCT (
{
    int16_t x;
    int16_t y;
    int16_t dx;
    int16_t dy;
    int16_t bbox[2][4];
    int32_t children[2];
}) mapnode_zdbsp_t;

typedef PACKED_STRUCT (
{
    uint32_t numsegs;
}) mapsubsector_zdbsp_t;

// [FG] support maps with NODES in compressed or uncompressed ZDBSP format
//      or DeePBSP format

mapformat_t P_CheckMapFormat (int lumpnum)
{
    mapformat_t format = MFMT_DOOMBSP;
    byte *nodes = NULL;
    int b;

#if 0  // [MB] 2020-04-21: Hexen format was already checked in p_setup.c
    if ((b = lumpnum+ML_BLOCKMAP+1) < numlumps &&
        !strcasecmp(lumpinfo[b].name, "BEHAVIOR"))
        I_Error("P_CheckMapFormat: Hexen map format not supported in %s.\n",
                lumpinfo[lumpnum-ML_NODES].name);
#endif

    // [MB] 2020-04-21: Check for <numlumps removed (numlumps not available)
    b = lumpnum+ML_NODES;
    if ((nodes = W_CacheLumpNum(b, PU_STATIC)) && W_LumpLength(b) > 8)
    {
        if (!memcmp(nodes, "xNd4\0\0\0\0", 8))
            format = MFMT_DEEPBSP;
        else if (!memcmp(nodes, "XNOD", 4))
            format = MFMT_ZDBSPX;
        else if (!memcmp(nodes, "ZNOD", 4))
            format = MFMT_ZDBSPZ;
    }

    if (nodes)
        Z_Free(nodes);

    return format;
}

// [FG] recalculate seg offsets

static fixed_t GetOffset(vertex_t *v1, vertex_t *v2)
{
    fixed_t dx, dy;
    fixed_t r;

    dx = (v1->x - v2->x)>>FRACBITS;
    dy = (v1->y - v2->y)>>FRACBITS;
    r = (fixed_t)(sqrt(dx*dx + dy*dy))<<FRACBITS;

    return r;
}

// [FG] support maps with DeePBSP nodes

void P_LoadSegs_DeePBSP (int lump)
{
    int  i;
    byte *data;
    int32_t vn1, vn2;

    numsegs = W_LumpLength(lump) / sizeof(mapseg_deepbsp_t);
    segs = Z_Malloc(numsegs*sizeof(seg_t),PU_LEVEL,0);
    memset(segs, 0, numsegs*sizeof(seg_t));
    data = W_CacheLumpNum(lump,PU_STATIC);

    for (i=0; i<numsegs; i++)
    {
        seg_t *li = segs+i;
        mapseg_deepbsp_t *ml = (mapseg_deepbsp_t *) data + i;

        int side, linedef;
        line_t *ldef;

        vn1 = LE_SWAP32(ml->v1);
        vn2 = LE_SWAP32(ml->v2);
        // [MB] 2020-04-21: Detect buggy wad (same as for normal nodes)
        if( vn1 > numvertexes || vn2 > numvertexes )
        {
            I_SoftError("P_LoadSegs_DeePBSP: Seg vertex bad %i,%i\n",
                        (int) vn1, (int) vn2 );
            // zero both out together, make seg safer
            // (otherwise will cross another line)
            vn1 = vn2 = 0;
        }
        li->v1 = &vertexes[vn1];
        li->v2 = &vertexes[vn2];

#ifdef HWRENDER
        // [MB] 2020-04-21: Added (same as for normal nodes)
        li->pv1 = li->pv2 = NULL;
        li->length = P_SegLength (li);
        li->lightmaps = NULL; // list of static lightmap for this seg
#endif

        li->angle = ((uint16_t)( LE_SWAP16(ml->angle) ))<<16;
        li->offset = (LE_SWAP16(ml->offset))<<16;
        linedef = (uint16_t)( LE_SWAP16(ml->linedef) );

        // [MB] 2020-04-21: Detect buggy wad (same as for normal nodes)
        if( linedef > numlines )
        {
            I_SoftError( "P_LoadSegs_DeePBSP: linedef #%i > numlines %i\n",
                         linedef, numlines );
            linedef = 0; // default
        }

        ldef = &lines[linedef];
        li->linedef = ldef;
        side = LE_SWAP16(ml->side);

        // [MB] 2020-04-21: Detect buggy wad (same as for normal nodes)
        if( side != 0 && side != 1 )
        {
            I_SoftError( "P_LoadSegs_DeePBSP: bad side index\n");
            side = 0;  // assume was using wrong side
        }
        // side1 required to have sidenum != NULL_INDEX
        if( ldef->sidenum[side] == NULL_INDEX )
        {
            I_SoftError( "P_LoadSegs_DeePBSP: using missing sidedef\n");
            side = 0;  // assume was using wrong side
        }

        li->side = side;
        li->sidedef = &sides[ldef->sidenum[side]];
        li->frontsector = sides[ldef->sidenum[side]].sector;

        // killough 5/3/98: ignore 2s flag if second sidedef missing:
        if (ldef->flags & ML_TWOSIDED && ldef->sidenum[side^1]!=NULL_INDEX)
            li->backsector = sides[ldef->sidenum[side^1]].sector;
        else
            li->backsector = 0;

        // [MB] 2020-04-21: Added (same as for normal nodes)
        li->numlights = 0;
        li->rlights = NULL;
    }

    Z_Free (data);
}

void P_LoadSubsectors_DeePBSP (int lump)
{
    mapsubsector_deepbsp_t *data;
    int  i;

    numsubsectors = W_LumpLength (lump) / sizeof(mapsubsector_deepbsp_t);
    subsectors = Z_Malloc(numsubsectors*sizeof(subsector_t),PU_LEVEL,0);
    data = (mapsubsector_deepbsp_t *)W_CacheLumpNum(lump, PU_STATIC);

    memset(subsectors, 0, numsubsectors*sizeof(subsector_t));

    for (i=0; i<numsubsectors; i++)
    {
        subsectors[i].numlines = (uint16_t)( LE_SWAP16(data[i].numsegs) );
        subsectors[i].firstline = (uint32_t)( LE_SWAP32(data[i].firstseg) );
    }

    Z_Free (data);
}

void P_LoadNodes_DeePBSP (int lump)
{
    byte *data;
    int  i;

    numnodes = W_LumpLength (lump) / sizeof(mapnode_deepbsp_t);
    nodes = Z_Malloc (numnodes*sizeof(node_t),PU_LEVEL,0);
    data = W_CacheLumpNum (lump, PU_STATIC);

    // [FG] skip header
    data += 8;

    // [MB] 2020-04-21: Added similar check as for normal nodes
    // No nodes and one subsector is a trivial but legal map.
    if( (numnodes < 1) && (numsubsectors > 1) )
    {
        I_SoftError("P_LoadNodes_DeePBSP: Bad node data\n");
        return;
    }

    for (i=0; i<numnodes; i++)
    {
        node_t *no = nodes + i;
        mapnode_deepbsp_t *mn = (mapnode_deepbsp_t *) data + i;
        int j;

        no->x = LE_SWAP16(mn->x)<<FRACBITS;
        no->y = LE_SWAP16(mn->y)<<FRACBITS;
        no->dx = LE_SWAP16(mn->dx)<<FRACBITS;
        no->dy = LE_SWAP16(mn->dy)<<FRACBITS;

        for (j=0 ; j<2 ; j++)
        {
            int k;
            no->children[j] = LE_SWAP32(mn->children[j]);

            for (k=0 ; k<4 ; k++)
                no->bbox[j][k] = LE_SWAP16(mn->bbox[j][k])<<FRACBITS;
        }
    }

    W_CacheLumpNum(lump, PU_CACHE);
}

// [FG] support maps with compressed or uncompressed ZDBSP nodes
// adapted from prboom-plus/src/p_setup.c:1040-1331
// heavily modified, condensed and simplyfied
// - removed most paranoid checks, brought in line with Vanilla P_LoadNodes()
// - removed const type punning pointers
// - inlined P_LoadZSegs()
// - added support for compressed ZDBSP nodes
// - added support for flipped levels

void P_LoadNodes_ZDBSP (int lump, boolean compressed)
{
    byte *data;
    uint32_t i;
#ifdef HAVE_ZLIB
    byte *output;
#endif  // HAVE_ZLIB

    uint32_t orgVerts, newVerts;
    uint32_t numSubs, currSeg;
    uint32_t numSegs;
    uint32_t numNodes;
    vertex_t *newvertarray = NULL;

    data = W_CacheLumpNum(lump, PU_LEVEL);

    // 0. Uncompress nodes lump (or simply skip header)

    if (compressed)
    {
#ifdef HAVE_ZLIB
        const int len =  W_LumpLength(lump);
        int outlen, err;
        z_stream *zstream;

        // first estimate for compression rate:
        // output buffer size == 2.5 * input size
        outlen = 2.5 * len;
        output = Z_Malloc(outlen, PU_STATIC, 0);

        // initialize stream state for decompression
        zstream = malloc(sizeof(*zstream));
        if (NULL == zstream)
            I_Error("P_LoadNodes: "
                    "Out of memory during ZDBSP nodes decrompression!");
        memset(zstream, 0, sizeof(*zstream));
        zstream->next_in = data + 4;
        zstream->avail_in = len - 4;
        zstream->next_out = output;
        zstream->avail_out = outlen;

        if (inflateInit(zstream) != Z_OK)
            I_Error("P_LoadNodes: "
                    "Error during ZDBSP nodes decompression initialization!");

        // resize if output buffer runs full
        while ((err = inflate(zstream, Z_SYNC_FLUSH)) == Z_OK)
        {
            int outlen_old = outlen;
            outlen = 2 * outlen_old;
#   if 0
            output = Z_Realloc(output, outlen, PU_STATIC, 0);
#   else
            // DooM Legacy has no Z_Realloc()
            byte *output_new;

            output_new = Z_Malloc(outlen, PU_STATIC, 0);
            memcpy( (void*)output_new, (void*)output, (size_t)outlen_old);
            Z_Free(output);
            output = output_new;
#   endif
            zstream->next_out = output + outlen_old;
            zstream->avail_out = outlen - outlen_old;
        }

        if (err != Z_STREAM_END)
            I_Error("P_LoadNodes: Error during ZDBSP nodes decompression!");

        GenPrintf(EMSG_info,
                  "P_LoadNodes: ZDBSP nodes compression ratio %.3f\n",
                  (float)zstream->total_out/zstream->total_in);

        data = output;

        if (inflateEnd(zstream) != Z_OK)
            I_Error("P_LoadNodes: "
                    "Error during ZDBSP nodes decompression shut-down!");

        // release the original data lump
        W_CacheLumpNum(lump, PU_CACHE);
        free(zstream);
#else  // HAVE_ZLIB
        I_Error("P_LoadNodes: ZDBSP nodes decompression requires zlib!");
#endif  // HAVE_ZLIB
    }
    else
    {
        // skip header
        data += 4;
    }

    // 1. Load new vertices added during node building

    orgVerts = (uint32_t)LE_SWAP32(*((uint32_t*)data));
    data += sizeof(orgVerts);

    newVerts = (uint32_t)LE_SWAP32(*((uint32_t*)data));
    data += sizeof(newVerts);

    if (orgVerts + newVerts == (unsigned int)numvertexes)
    {
        newvertarray = vertexes;
    }
    else
    {
        newvertarray = Z_Malloc((orgVerts + newVerts) * sizeof(vertex_t),
                                 PU_LEVEL, 0);
        memcpy(newvertarray, vertexes, orgVerts * sizeof(vertex_t));
        memset(newvertarray + orgVerts, 0, newVerts * sizeof(vertex_t));
    }

    for (i = 0; i < newVerts; i++)
    {
#if 0  // [MB] 2020-04-21: DooM Legacy has no separate renderer coordinates
        newvertarray[i + orgVerts].r_x =
#endif
            newvertarray[i + orgVerts].x = LE_SWAP32(*((uint32_t*)data));
        data += sizeof(newvertarray[0].x);

#if 0  // [MB] 2020-04-21: DooM Legacy has no separate renderer coordinates
        newvertarray[i + orgVerts].r_y =
#endif
            newvertarray[i + orgVerts].y = LE_SWAP32(*((uint32_t*)data));
        data += sizeof(newvertarray[0].y);
    }

    if (vertexes != newvertarray)
    {
        for (i = 0; i < (uint32_t)numlines; i++)
        {
            lines[i].v1 = lines[i].v1 - vertexes + newvertarray;
            lines[i].v2 = lines[i].v2 - vertexes + newvertarray;
        }

        Z_Free(vertexes);
        vertexes = newvertarray;
        numvertexes = (int)(orgVerts + newVerts);
    }

    // 2. Load subsectors

    numSubs = (uint32_t)LE_SWAP32(*((uint32_t*)data));
    data += sizeof(numSubs);

    if (0 == numSubs)
        I_Error("P_LoadNodes_ZDBSP: No subsectors in map!");

    numsubsectors = (int)numSubs;
    subsectors = Z_Malloc(numsubsectors * sizeof(subsector_t), PU_LEVEL, 0);

    for (i = currSeg = 0; i < numsubsectors; i++)
    {
        mapsubsector_zdbsp_t *mseg = (mapsubsector_zdbsp_t*) data + i;

        subsectors[i].firstline = currSeg;
        subsectors[i].numlines = (uint32_t)LE_SWAP32(mseg->numsegs);
        currSeg += (uint32_t)LE_SWAP32(mseg->numsegs);
    }

    data += numsubsectors * sizeof(mapsubsector_zdbsp_t);

    // 3. Load segs

    numSegs = (uint32_t)LE_SWAP32(*((uint32_t*)data));
    data += sizeof(numSegs);

    // The number of stored segs should match the number of segs used by
    // subsectors
    if (numSegs != currSeg)
    {
        I_Error("P_LoadNodes_ZDBSP: Incorrect number of segs in ZDBSP nodes!");
    }

    numsegs = (int)numSegs;
    segs = Z_Malloc(numsegs * sizeof(seg_t), PU_LEVEL, 0);

    for (i = 0; i < (uint32_t)numsegs; i++)
    {
        line_t *ldef;
        unsigned int linedef;
        unsigned char side;
        seg_t *li = segs + i;
        mapseg_zdbsp_t *ml = (mapseg_zdbsp_t *) data + i;
        int32_t vn1, vn2;

        vn1 = LE_SWAP32(ml->v1);
        vn2 = LE_SWAP32(ml->v2);
        // [MB] 2020-04-21: Detect buggy wad (same as for normal nodes)
        if( vn1 > numvertexes || vn2 > numvertexes )
        {
            I_SoftError("P_LoadSegs_ZDBSP: Seg vertex bad %i,%i\n",
                        (int) vn1, (int) vn2 );
            // zero both out together, make seg safer
            // (otherwise will cross another line)
            vn1 = vn2 = 0;
        }
        li->v1 = &vertexes[vn1];
        li->v2 = &vertexes[vn2];

#ifdef HWRENDER
        // [MB] 2020-04-22: Added (same as for normal nodes)
        li->pv1 = li->pv2 = NULL;
        li->length = P_SegLength (li);
        li->lightmaps = NULL; // list of static lightmap for this seg
#endif

        linedef = (uint16_t)( LE_SWAP16(ml->linedef) );
        ldef = &lines[linedef];
        li->linedef = ldef;
        side = ml->side;

        // e6y: check for wrong indexes
        if ((unsigned)ldef->sidenum[side] >= (unsigned)numsides)
        {
            I_Error("P_LoadSegs_ZDBSP: linedef %u for seg %u "
                    "references a non-existent sidedef %u",
                    linedef, (unsigned) i, (unsigned)ldef->sidenum[side]);
        }

        li->sidedef = &sides[ldef->sidenum[side]];
        li->frontsector = sides[ldef->sidenum[side]].sector;

        // seg angle and offset are not included
        li->angle = R_PointToAngle2(segs[i].v1->x, segs[i].v1->y,
                                    segs[i].v2->x, segs[i].v2->y);
        li->offset = GetOffset(li->v1, (ml->side ? ldef->v2 : ldef->v1));

        // killough 5/3/98: ignore 2s flag if second sidedef missing:
        if (ldef->flags & ML_TWOSIDED && ldef->sidenum[side^1]!=NULL_INDEX)
            li->backsector = sides[ldef->sidenum[side^1]].sector;
        else
            li->backsector = 0;
    }

    data += numsegs * sizeof(mapseg_zdbsp_t);

    // 4. Load nodes

    numNodes = (uint32_t)LE_SWAP32(*((uint32_t*)data));
    data += sizeof(numNodes);

    numnodes = (int)numNodes;
    nodes = Z_Malloc(numnodes * sizeof(node_t), PU_LEVEL, 0);

    for (i = 0; i < numnodes; i++)
    {
        int j, k;
        node_t *no = nodes + i;
        mapnode_zdbsp_t *mn = (mapnode_zdbsp_t *) data + i;

        no->x = LE_SWAP16(mn->x)<<FRACBITS;
        no->y = LE_SWAP16(mn->y)<<FRACBITS;
        no->dx = LE_SWAP16(mn->dx)<<FRACBITS;
        no->dy = LE_SWAP16(mn->dy)<<FRACBITS;

        for (j = 0; j < 2; j++)
        {
            no->children[j] = (uint32_t)LE_SWAP32(mn->children[j]);

            for (k = 0; k < 4; k++)
                no->bbox[j][k] = LE_SWAP16(mn->bbox[j][k])<<FRACBITS;
        }
    }

#ifdef HAVE_ZLIB
    if (compressed)
        Z_Free(output);
    else
#endif  // HAVE_ZLIB
        W_CacheLumpNum(lump, PU_CACHE);
}
