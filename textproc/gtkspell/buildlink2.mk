# $NetBSD: buildlink2.mk,v 1.6 2003/12/13 00:45:25 wiz Exp $
#
# This Makefile fragment is included by packages that use gtkspell.
#
# This file was created automatically using createbuildlink 2.0.
#

.if !defined(GTKSPELL_BUILDLINK2_MK)
GTKSPELL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gtkspell
BUILDLINK_DEPENDS.gtkspell?=		gtkspell>=2.0.2nb5
BUILDLINK_PKGSRCDIR.gtkspell?=		../../textproc/gtkspell

EVAL_PREFIX+=	BUILDLINK_PREFIX.gtkspell=gtkspell
BUILDLINK_PREFIX.gtkspell_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gtkspell+=	include/gtkspell-2.0/gtkspell/gtkspell.h
BUILDLINK_FILES.gtkspell+=	lib/libgtkspell.*
BUILDLINK_FILES.gtkspell+=	lib/pkgconfig/gtkspell-2.0.pc

.include "../../textproc/aspell/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	gtkspell-buildlink

gtkspell-buildlink: _BUILDLINK_USE

.endif	# GTKSPELL_BUILDLINK2_MK
