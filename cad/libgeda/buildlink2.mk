# $NetBSD: buildlink2.mk,v 1.1 2002/12/13 05:19:52 dmcmahill Exp $
#
# This Makefile fragment is included by packages that use libgeda.
#
# This file was created automatically using createbuildlink 2.2.
#

.if !defined(LIBGEDA_BUILDLINK2_MK)
LIBGEDA_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libgeda
BUILDLINK_DEPENDS.libgeda?=		libgeda>=20021103
BUILDLINK_PKGSRCDIR.libgeda?=		../../cad/libgeda

EVAL_PREFIX+=	BUILDLINK_PREFIX.libgeda=libgeda
BUILDLINK_PREFIX.libgeda_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.libgeda+=	include/libgeda/colors.h
BUILDLINK_FILES.libgeda+=	include/libgeda/defines.h
BUILDLINK_FILES.libgeda+=	include/libgeda/funcs.h
BUILDLINK_FILES.libgeda+=	include/libgeda/globals.h
BUILDLINK_FILES.libgeda+=	include/libgeda/libgeda.h
BUILDLINK_FILES.libgeda+=	include/libgeda/o_types.h
BUILDLINK_FILES.libgeda+=	include/libgeda/prototype.h
BUILDLINK_FILES.libgeda+=	include/libgeda/struct.h
BUILDLINK_FILES.libgeda+=	lib/libgeda.*

.include "../../devel/libstroke/buildlink2.mk"
.include "../../graphics/libgdgeda/buildlink2.mk"
.include "../../lang/guile/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

BUILDLINK_TARGETS+=	libgeda-buildlink

libgeda-buildlink: _BUILDLINK_USE

.endif	# LIBGEDA_BUILDLINK2_MK
