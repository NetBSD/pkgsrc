# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/01/27 09:36:26 jmmv Exp $
#
# This Makefile fragment is included by packages that use gnome1-dirs.
#
# This file was created automatically using createbuildlink 2.3.
#

.if !defined(GNOME1_DIRS_BUILDLINK2_MK)
GNOME1_DIRS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnome1-dirs
BUILDLINK_DEPENDS.gnome1-dirs?=		gnome1-dirs>=1.0
BUILDLINK_PKGSRCDIR.gnome1-dirs?=	../../misc/gnome1-dirs

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnome1-dirs=gnome1-dirs
BUILDLINK_PREFIX.gnome1-dirs_DEFAULT=	${X11PREFIX}

BUILDLINK_TARGETS+=	gnome1-dirs-buildlink

gnome1-dirs-buildlink: _BUILDLINK_USE

.endif	# GNOME1_DIRS_BUILDLINK2_MK
