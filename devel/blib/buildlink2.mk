# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/12/27 22:37:44 salo Exp $
#
# This Makefile fragment is included by packages that use blib.
#

.if !defined(BLIB_BUILDLINK2_MK)
BLIB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			blib
BUILDLINK_DEPENDS.blib?=		blib>=1.0.2
BUILDLINK_PKGSRCDIR.blib?=		../../devel/blib

EVAL_PREFIX+=	BUILDLINK_PREFIX.blib=blib
BUILDLINK_PREFIX.blib_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.blib+=	include/blib-1.0/blib/*.h
BUILDLINK_FILES.blib+=	lib/libb-1.0.*
BUILDLINK_FILES.blib+=	lib/libb-gtk-1.0.*
BUILDLINK_FILES.blib+=	lib/libb-gtk.*
BUILDLINK_FILES.blib+=	lib/libb.*

.include "../../x11/gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	blib-buildlink

blib-buildlink: _BUILDLINK_USE

.endif	# BLIB_BUILDLINK2_MK
