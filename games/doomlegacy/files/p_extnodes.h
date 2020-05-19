// Emacs style mode select   -*- C++ -*- 
//-----------------------------------------------------------------------------
//
// $Id: p_extnodes.h,v 1.1 2020/05/19 11:20:16 micha Exp $
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


#ifndef __P_EXTNODES__
#define __P_EXTNODES__

// [MB] 2020-04-21: Support for ZDoom extended nodes based on woof 1.2.0

// [MB] 2020-04-21: Moved from woof doomtype.h to this header
// The packed attribute forces structures to be packed into the minimum
// space necessary.  If this is not done, the compiler may align structure
// fields differently to optimize memory access, inflating the overall
// structure size.  It is important to use the packed attribute on certain
// structures where alignment is important, particularly data read/written
// to disk.

#ifdef __GNUC__
 #if defined(_WIN32) && !defined(__clang__)
  #define PACKEDATTR __attribute__((packed,gcc_struct))
 #else
  #define PACKEDATTR __attribute__((packed))
 #endif

 #define PRINTF_ATTR(fmt, first) __attribute__((format(printf, fmt, first)))
 #define PRINTF_ARG_ATTR(x) __attribute__((format_arg(x)))
 #define NORETURN __attribute__((noreturn))
#else
 #if defined(_MSC_VER)
  #define PACKEDATTR __pragma(pack(pop))
 #else
  #define PACKEDATTR
 #endif

 #define PRINTF_ATTR(fmt, first)
 #define PRINTF_ARG_ATTR(x)
 #define NORETURN
#endif

#ifdef __WATCOMC__
 #define PACKEDPREFIX _Packed
#elif defined(_MSC_VER)
 #define PACKEDPREFIX __pragma(pack(push,1))
#else
 #define PACKEDPREFIX
#endif

#define PACKED_STRUCT(...) PACKEDPREFIX struct __VA_ARGS__ PACKEDATTR

typedef enum
{
    MFMT_DOOMBSP = 0x000,
    MFMT_DEEPBSP = 0x001,
    MFMT_ZDBSPX  = 0x002,
    MFMT_ZDBSPZ  = 0x004,
} mapformat_t;

extern mapformat_t P_CheckMapFormat (int lumpnum);

extern void P_LoadSegs_DeePBSP (int lump);
extern void P_LoadSubsectors_DeePBSP (int lump);
extern void P_LoadNodes_DeePBSP (int lump);
extern void P_LoadNodes_ZDBSP (int lump, boolean compressed);

#endif
