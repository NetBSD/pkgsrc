# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:23:14 jlam Exp $

.if !defined(GNOME_PRINT_BUILDLINK2_MK)
GNOME_PRINT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnome-print
BUILDLINK_DEPENDS.gnome-print?=		gnome-print>=0.29nb1
BUILDLINK_PKGSRCDIR.gnome-print?=	../../print/gnome-print

EVAL_PREFIX+=			BUILDLINK_PREFIX.gnome-print=gnome-print
BUILDLINK_PREFIX.gnome-print_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gnome-print+=	include/gnome-1.0/libgnomeprint/*
BUILDLINK_FILES.gnome-print+=	lib/libgnomeprint.*

.include "../../graphics/gdk-pixbuf-gnome/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"

BUILDLINK_TARGETS+=	gnome-print-buildlink

gnome-print-buildlink: _BUILDLINK_USE

.endif	# GNOME_PRINT_BUILDLINK2_MK
