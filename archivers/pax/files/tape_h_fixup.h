/*	$NetBSD: tape_h_fixup.h,v 1.1 2003/12/05 16:35:54 erh Exp $ */

/*
 * Mapping from the mtio.h defines and structures to
 * the tape.h ones.
 */

#ifndef _TAPE_H_FIXUP
#define _TAPE_H_FIXUP

#define MTIOCTOP   STIOCTOP
#define MTIOCMD    STIOCMD
#define MTIOCHGP   STIOCHGP
#define mtop stop
#define mt_op st_op
#define mt_count st_count

#define MTOFFL     STOFFL
#define MTREW      STREW
#define MTERASE    STERASE
#define MTRETEN    STRETEN
#define MTWEOF     STWEOF
#define MTFSF      STFSF
#define MTBSF      STRSF
#define MTFSR      STFSR
#define MTBSR      STRSR
#define MTINSRT    STINSRT
#define MTEJECT    STEJECT
#define MTDEOF     STDEOF

/* mtget and MTIOCGET aren't anywhere that I could find. */
struct	mtget
{
	short	mt_type;
	short	mt_dsreg;
	short	mt_erreg;
	daddr_t	mt_resid;
	daddr_t	mt_fileno;
	daddr_t	mt_blkno;
};

#define MTIOCGET _IOR('m', 2, struct mtget)

#endif
