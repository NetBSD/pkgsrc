# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/01/27 09:35:25 jmmv Exp $
#
# This Makefile fragment is included by packages that use gnome1-dirs.
#
# This file was created automatically using createbuildlink 2.3.
#

.if !defined(GNOME_DIRS_BUILDLINK2_MK)
GNOME_DIRS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnome-dirs
BUILDLINK_DEPENDS.gnome-dirs?=		gnome-dirs>=1.0
BUILDLINK_PKGSRCDIR.gnome-dirs?=	../../misc/gnome-dirs

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnome-dirs=gnome-dirs
BUILDLINK_PREFIX.gnome-dirs_DEFAULT=	${X11PREFIX}

BUILDLINK_TARGETS+=	gnome-dirs-buildlink

gnome-dirs-buildlink: _BUILDLINK_USE

.endif	# GNOME_DIRS_BUILDLINK2_MK
