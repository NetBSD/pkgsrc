# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/01/27 09:37:14 jmmv Exp $
#
# This Makefile fragment is included by packages that use gnome2-dirs.
#
# This file was created automatically using createbuildlink 2.3.
#

.if !defined(GNOME2_DIRS_BUILDLINK2_MK)
GNOME2_DIRS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnome2-dirs
BUILDLINK_DEPENDS.gnome2-dirs?=		gnome2-dirs>=1.0
BUILDLINK_PKGSRCDIR.gnome2-dirs?=	../../misc/gnome2-dirs

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnome2-dirs=gnome2-dirs
BUILDLINK_PREFIX.gnome2-dirs_DEFAULT=	${LOCALBASE}

BUILDLINK_TARGETS+=	gnome2-dirs-buildlink

gnome2-dirs-buildlink: _BUILDLINK_USE

.endif	# GNOME2_DIRS_BUILDLINK2_MK
