# $NetBSD: buildlink2.mk,v 1.1 2002/12/13 02:59:26 dmcmahill Exp $
#
# This Makefile fragment is included by packages that use libgdgeda.
#
# This file was created automatically using createbuildlink 2.2.
#

.if !defined(LIBGDGEDA_BUILDLINK2_MK)
LIBGDGEDA_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libgdgeda
BUILDLINK_DEPENDS.libgdgeda?=		libgdgeda>=1.8nb1
BUILDLINK_PKGSRCDIR.libgdgeda?=		../../graphics/libgdgeda

EVAL_PREFIX+=	BUILDLINK_PREFIX.libgdgeda=libgdgeda
BUILDLINK_PREFIX.libgdgeda_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libgdgeda+=	include/gdgeda/gd.h
BUILDLINK_FILES.libgdgeda+=	include/gdgeda/gd_io.h
BUILDLINK_FILES.libgdgeda+=	include/gdgeda/gdfontg.h
BUILDLINK_FILES.libgdgeda+=	include/gdgeda/gdfontl.h
BUILDLINK_FILES.libgdgeda+=	include/gdgeda/gdfontmb.h
BUILDLINK_FILES.libgdgeda+=	include/gdgeda/gdfonts.h
BUILDLINK_FILES.libgdgeda+=	include/gdgeda/gdfontt.h
BUILDLINK_FILES.libgdgeda+=	include/gdgeda/gdcache.h
BUILDLINK_FILES.libgdgeda+=	include/gdgeda/jisx0208.h
BUILDLINK_FILES.libgdgeda+=	include/gdgeda/wbmp.h
BUILDLINK_FILES.libgdgeda+=	lib/libgdgeda.*


BUILDLINK_TARGETS+=	libgdgeda-buildlink

libgdgeda-buildlink: _BUILDLINK_USE

.endif	# LIBGDGEDA_BUILDLINK2_MK
