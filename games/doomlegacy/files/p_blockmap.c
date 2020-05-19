//
// Copyright(C) 1993-1996 Id Software, Inc.
// Copyright(C) 1999 id Software, Chi Hoang, Lee Killough, Jim Flynn,
//                   Rand Phares, Ty Halderman
// Copyright(C) 2005-2014 Simon Howard
// Copyright(C) 2017 Fabian Greffrath
// Copyright(C) 2020 by DooM Legacy Team
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// DESCRIPTION:
// [crispy] Create Blockmap
// [MB] 2020-05-13: Description of blockmap lump format:
//      https://doomwiki.org/wiki/Blockmap
//

#include <stdint.h>      // [MB] 2020-05-13: Added for C99 integer data types
#include <stdlib.h>
#include <string.h>      // [MB] 2020-05-12: Added for memset()

//#include "i_system.h"  // [MB] 2020-05-12: I_Realloc() is now here
#include "doomincl.h"    // [MB] 2020-05-12: Added for I_Error()
#include "p_local.h"
#include "r_state.h"
#include "z_zone.h"


// I_Realloc
/*
 * [MB] 2020-05-12: Ported from Crispy Doom 5.8.0 (src/i_system.c)
 * - Reject zero new size (would be implementation defined behaviour)
 * - Use (unsigned long) for I_Error() (size is not a pointer)
 */
static void *I_Realloc(void *ptr, size_t size)
{
    void *new_ptr = NULL;

    if (0 == size)
        I_Error("I_Realloc: Failed on zero new size");
    else
    {
        new_ptr = realloc(ptr, size);
        if (NULL == new_ptr)
            I_Error("I_Realloc: Failed on reallocation of %lu bytes",
                    (unsigned long) size);
    }

    return new_ptr;
}


// [crispy] taken from mbfsrc/P_SETUP.C:547-707, slightly adapted
/*
 *  [MB] 2020-05-12: Ported from Crispy Doom 5.8.0 (src/doom/p_blockmap.c)
 *  - Change indentation to 4 SPs (matching DooM Legacy style)
 *  - Replace blockmap with blockmapindex (int32_t* => uint32_t*)
 *    Global pointer to header of the blockmap lump
 *  - Replace blockmaplump with blockmaphead (int32_t* => uint32_t*)
 *    Global pointer to beginning of the part containing the offsets
 *  - Added typecasts for unsigned target types
 */
void P_CreateBlockMap(void)
{
    register int i;
    fixed_t minx = INT_MAX, miny = INT_MAX;
    fixed_t maxx = INT_MIN, maxy = INT_MIN;

    // First find limits of map
    for (i=0 ; i<numvertexes ; i++)
    {
        if (vertexes[i].x >> FRACBITS < minx)
            minx = vertexes[i].x >> FRACBITS;
        else if (vertexes[i].x >> FRACBITS > maxx)
            maxx = vertexes[i].x >> FRACBITS;
        if (vertexes[i].y >> FRACBITS < miny)
            miny = vertexes[i].y >> FRACBITS;
        else if (vertexes[i].y >> FRACBITS > maxy)
            maxy = vertexes[i].y >> FRACBITS;
    }

    // [crispy] doombsp/DRAWING.M:175-178
    minx -= 8; miny -= 8;
    maxx += 8; maxy += 8;

    // Save blockmap parameters
    bmaporgx = minx << FRACBITS;
    bmaporgy = miny << FRACBITS;
    bmapwidth  = ((maxx-minx) >> MAPBTOFRAC) + 1;
    bmapheight = ((maxy-miny) >> MAPBTOFRAC) + 1;

    // Compute blockmap, which is stored as a 2d array of variable-sized lists
    //
    // Pseudocode:
    //
    // For each linedef:
    //
    //   Map the starting and ending vertices to blocks.
    //
    //   Starting in the starting vertex's block, do:
    //
    //     Add linedef to current block's list, dynamically resizing it.
    //
    //     If current block is the same as the ending vertex's block,
    //     exit loop.
    //
    //     Move to an adjacent block by moving towards the ending block in
    //     either the x or y direction, to the block which contains the
    //     linedef.
    {
        typedef struct { int n, nalloc, *list; } bmap_t;  // blocklist structure
        unsigned tot = bmapwidth * bmapheight;            // size of blockmap
        bmap_t *bmap = calloc(sizeof *bmap, tot);         // array of blocklists
        int x, y, adx, ady, bend;

        for (i=0; i < numlines; i++)
        {
            int dx, dy, diff, b;

            // starting coordinates
            x = (lines[i].v1->x >> FRACBITS) - minx;
            y = (lines[i].v1->y >> FRACBITS) - miny;

            // x-y deltas
            adx = lines[i].dx >> FRACBITS, dx = adx < 0 ? -1 : 1;
            ady = lines[i].dy >> FRACBITS, dy = ady < 0 ? -1 : 1;

            // difference in preferring to move across y (>0) instead of x (<0)
            diff = !adx ? 1 : !ady ? -1 :
                ( ((x >> MAPBTOFRAC) << MAPBTOFRAC) +
                    (dx > 0 ? MAPBLOCKUNITS-1 : 0) - x ) *
                    (ady = abs(ady)) * dx -
                ( ((y >> MAPBTOFRAC) << MAPBTOFRAC) +
                    (dy > 0 ? MAPBLOCKUNITS-1 : 0) - y ) *
                    (adx = abs(adx)) * dy;

            // starting block, and pointer to its blocklist structure
            b = (y >> MAPBTOFRAC)*bmapwidth + (x >> MAPBTOFRAC);

            // ending block
            bend = (((lines[i].v2->y >> FRACBITS) - miny) >> MAPBTOFRAC) *
                bmapwidth +
                    (((lines[i].v2->x >> FRACBITS) - minx) >> MAPBTOFRAC);

            // delta for pointer when moving across y
            dy *= bmapwidth;

            // deltas for diff inside the loop
            adx <<= MAPBTOFRAC;
            ady <<= MAPBTOFRAC;

            // Now we simply iterate block-by-block until we reach the end block
            while ((unsigned) b < tot)    // failsafe -- should ALWAYS be true
            {
                // Increase size of allocated list if necessary
                if (bmap[b].n >= bmap[b].nalloc)
                    bmap[b].list = I_Realloc(bmap[b].list,
                        ( bmap[b].nalloc = bmap[b].nalloc ?
                            bmap[b].nalloc*2 : 8 ) *
                            sizeof*bmap->list);

                // Add linedef to end of list
                bmap[b].list[bmap[b].n++] = i;

                // If we have reached the last block, exit
                if (b == bend)
                    break;

                // Move in either the x or y direction to the next block
                if (diff < 0)
                    diff += ady, b += dx;
                else
                    diff -= adx, b += dy;
            }
        }

        // Compute the total size of the blockmap.
        //
        // Compression of empty blocks is performed by reserving two offset
        // words at tot and tot+1.
        //
        // 4 words, unused if this routine is called, are reserved at the start.
        {
            int count = tot+6;  // we need at least 1 word per block,
                                // plus reserved's

            for (i = 0; i < tot; i++)
                if (bmap[i].n)
                    count += bmap[i].n + 2; // 1 header word + 1 trailer word +
                                            // blocklist

            // Allocate blockmap lump with computed count
            blockmaphead = Z_Malloc(sizeof(*blockmaphead) * count, PU_LEVEL, 0);
        }

        // Now compress the blockmap.
        {
            int ndx = tot += 4;       // Advance index to start of linedef lists
            bmap_t *bp = bmap;        // Start of uncompressed blockmap

            blockmaphead[ndx++] = 0;  // Store an empty blockmap list at start
            blockmaphead[ndx++] = (uint32_t)INT32_C(-1); // (For compression)

            for (i = 4; i < tot; i++, bp++)
                if (bp->n)                               // Non-empty blocklist
                {
                                                         // Store index & header
                    blockmaphead[blockmaphead[i] = ndx++] = 0;
                    do
                                                         // Copy linedef list
                        blockmaphead[ndx++] = (uint32_t)(unsigned int)
                                              bp->list[--bp->n];
                    while (bp->n);
                                                         // Store trailer
                    blockmaphead[ndx++] = (uint32_t)INT32_C(-1);
                    free(bp->list);                      // Free linedef list
                }
                else       // Empty blocklist: point to reserved empty blocklist
                    blockmaphead[i] = tot;

        }

        // [MB] 2020-05-13: Moved outside of last nested block to make it more
        //                  obvious that the free() is always executed
        free(bmap);  // Free uncompressed blockmap
    }

#if 1
    // [MB] 2020-05-13: Populate blockmap lump header
    /*
     * Currently DooM Legacy 1.48 does not use this header. Maybe useful for
     * debugging.
     */
    {
        blockmaphead[0] = bmaporgx>>FRACBITS;  // x coordinate of grid origin
        blockmaphead[1] = bmaporgy>>FRACBITS;  // y coordinate of grid origin
        blockmaphead[2] = bmapwidth;           // Number of columns
        blockmaphead[3] = bmapheight;          // Number of rows
    }
#endif

    // [crispy] copied over from P_LoadBlockMap()
    // [MB] 2020-05-13: Modified to match "clear out mobj chains" of DooM Legacy
    {
        int count = sizeof(*blocklinks) * bmapwidth * bmapheight;

        blocklinks = Z_Malloc(count, PU_LEVEL, 0);
        memset(blocklinks, 0, count);
        //blockmapindex = blockmaphead+4;
        blockmapindex = & blockmaphead[4];
    }
}
