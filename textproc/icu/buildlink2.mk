# $NetBSD: buildlink2.mk,v 1.1 2002/10/28 22:49:15 seb Exp $
#
# This Makefile fragment is included by packages that use icu.
#
# This file was created automatically using createbuildlink 2.2.
# And then hand edited.
#

.if !defined(ICU_BUILDLINK2_MK)
ICU_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		icu
BUILDLINK_DEPENDS.icu?=		icu>=1.7
BUILDLINK_PKGSRCDIR.icu?=	../../textproc/icu

EVAL_PREFIX+=	BUILDLINK_PREFIX.icu=icu
BUILDLINK_PREFIX.icu_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.icu+=	include/unicode/bidi.h
BUILDLINK_FILES.icu+=	include/unicode/brkiter.h
BUILDLINK_FILES.icu+=	include/unicode/calendar.h
BUILDLINK_FILES.icu+=	include/unicode/chariter.h
BUILDLINK_FILES.icu+=	include/unicode/choicfmt.h
BUILDLINK_FILES.icu+=	include/unicode/coleitr.h
BUILDLINK_FILES.icu+=	include/unicode/coll.h
BUILDLINK_FILES.icu+=	include/unicode/convert.h
BUILDLINK_FILES.icu+=	include/unicode/cpdtrans.h
BUILDLINK_FILES.icu+=	include/unicode/datefmt.h
BUILDLINK_FILES.icu+=	include/unicode/dbbi.h
BUILDLINK_FILES.icu+=	include/unicode/dcfmtsym.h
BUILDLINK_FILES.icu+=	include/unicode/decimfmt.h
BUILDLINK_FILES.icu+=	include/unicode/docmain.h
BUILDLINK_FILES.icu+=	include/unicode/dtfmtsym.h
BUILDLINK_FILES.icu+=	include/unicode/fieldpos.h
BUILDLINK_FILES.icu+=	include/unicode/fmtable.h
BUILDLINK_FILES.icu+=	include/unicode/format.h
BUILDLINK_FILES.icu+=	include/unicode/gregocal.h
BUILDLINK_FILES.icu+=	include/unicode/hangjamo.h
BUILDLINK_FILES.icu+=	include/unicode/hextouni.h
BUILDLINK_FILES.icu+=	include/unicode/jamohang.h
BUILDLINK_FILES.icu+=	include/unicode/locid.h
BUILDLINK_FILES.icu+=	include/unicode/msgfmt.h
BUILDLINK_FILES.icu+=	include/unicode/normlzr.h
BUILDLINK_FILES.icu+=	include/unicode/nultrans.h
BUILDLINK_FILES.icu+=	include/unicode/numfmt.h
BUILDLINK_FILES.icu+=	include/unicode/parseerr.h
BUILDLINK_FILES.icu+=	include/unicode/parsepos.h
BUILDLINK_FILES.icu+=	include/unicode/platform.h
BUILDLINK_FILES.icu+=	include/unicode/pmacos.h
BUILDLINK_FILES.icu+=	include/unicode/pos2.h
BUILDLINK_FILES.icu+=	include/unicode/pos400.h
BUILDLINK_FILES.icu+=	include/unicode/putil.h
BUILDLINK_FILES.icu+=	include/unicode/pwin32.h
BUILDLINK_FILES.icu+=	include/unicode/rbbi.h
BUILDLINK_FILES.icu+=	include/unicode/rbt.h
BUILDLINK_FILES.icu+=	include/unicode/rep.h
BUILDLINK_FILES.icu+=	include/unicode/resbund.h
BUILDLINK_FILES.icu+=	include/unicode/schriter.h
BUILDLINK_FILES.icu+=	include/unicode/scsu.h
BUILDLINK_FILES.icu+=	include/unicode/simpletz.h
BUILDLINK_FILES.icu+=	include/unicode/smpdtfmt.h
BUILDLINK_FILES.icu+=	include/unicode/sortkey.h
BUILDLINK_FILES.icu+=	include/unicode/tblcoll.h
BUILDLINK_FILES.icu+=	include/unicode/timezone.h
BUILDLINK_FILES.icu+=	include/unicode/translit.h
BUILDLINK_FILES.icu+=	include/unicode/ubidi.h
BUILDLINK_FILES.icu+=	include/unicode/ubrk.h
BUILDLINK_FILES.icu+=	include/unicode/ucal.h
BUILDLINK_FILES.icu+=	include/unicode/uchar.h
BUILDLINK_FILES.icu+=	include/unicode/uchriter.h
BUILDLINK_FILES.icu+=	include/unicode/ucnv.h
BUILDLINK_FILES.icu+=	include/unicode/ucnv_cb.h
BUILDLINK_FILES.icu+=	include/unicode/ucnv_err.h
BUILDLINK_FILES.icu+=	include/unicode/ucol.h
BUILDLINK_FILES.icu+=	include/unicode/udat.h
BUILDLINK_FILES.icu+=	include/unicode/udata.h
BUILDLINK_FILES.icu+=	include/unicode/uloc.h
BUILDLINK_FILES.icu+=	include/unicode/umachine.h
BUILDLINK_FILES.icu+=	include/unicode/umisc.h
BUILDLINK_FILES.icu+=	include/unicode/umsg.h
BUILDLINK_FILES.icu+=	include/unicode/unicode.h
BUILDLINK_FILES.icu+=	include/unicode/unifilt.h
BUILDLINK_FILES.icu+=	include/unicode/unifltlg.h
BUILDLINK_FILES.icu+=	include/unicode/uniset.h
BUILDLINK_FILES.icu+=	include/unicode/unistr.h
BUILDLINK_FILES.icu+=	include/unicode/unitohex.h
BUILDLINK_FILES.icu+=	include/unicode/unorm.h
BUILDLINK_FILES.icu+=	include/unicode/unum.h
BUILDLINK_FILES.icu+=	include/unicode/urep.h
BUILDLINK_FILES.icu+=	include/unicode/ures.h
BUILDLINK_FILES.icu+=	include/unicode/ushape.h
BUILDLINK_FILES.icu+=	include/unicode/ustdio.h
BUILDLINK_FILES.icu+=	include/unicode/ustring.h
BUILDLINK_FILES.icu+=	include/unicode/utf.h
BUILDLINK_FILES.icu+=	include/unicode/utf16.h
BUILDLINK_FILES.icu+=	include/unicode/utf32.h
BUILDLINK_FILES.icu+=	include/unicode/utf8.h
BUILDLINK_FILES.icu+=	include/unicode/utrans.h
BUILDLINK_FILES.icu+=	include/unicode/utypes.h
BUILDLINK_FILES.icu+=	lib/icu/1.7/Makefile.inc
BUILDLINK_FILES.icu+=	lib/icu/1.7/lib*
BUILDLINK_FILES.icu+=	lib/icu/Makefile.inc
BUILDLINK_FILES.icu+=	lib/icu/current/Makefile.inc
BUILDLINK_FILES.icu+=	lib/icu/current/lib*
BUILDLINK_FILES.icu+=	lib/libicui18n.*
BUILDLINK_FILES.icu+=	lib/libicutoolutil.*
BUILDLINK_FILES.icu+=	lib/libicuuc.*
BUILDLINK_FILES.icu+=	lib/libustdio.*


BUILDLINK_TARGETS+=	icu-buildlink

icu-buildlink: _BUILDLINK_USE

.endif	# ICU_BUILDLINK2_MK
