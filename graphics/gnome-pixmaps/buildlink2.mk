# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/09/14 02:37:40 rh Exp $
#
# This Makefile fragment is included by packages that use gnome-pixmaps.
#
# This file was created automatically using createbuildlink 2.0.
#

.if !defined(GNOME_PIXMAPS_BUILDLINK2_MK)
GNOME_PIXMAPS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnome-pixmaps
BUILDLINK_DEPENDS.gnome-pixmaps?=		gnome-pixmaps>=1.4.2
BUILDLINK_PKGSRCDIR.gnome-pixmaps?=		../../graphics/gnome-pixmaps

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnome-pixmaps=gnome-pixmaps
BUILDLINK_PREFIX.gnome-pixmaps_DEFAULT=	${X11PREFIX}


BUILDLINK_TARGETS+=	gnome-pixmaps-buildlink

gnome-pixmaps-buildlink: _BUILDLINK_USE

.endif	# GNOME_PIXMAPS_BUILDLINK2_MK
