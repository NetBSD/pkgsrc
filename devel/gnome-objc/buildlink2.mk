# $NetBSD: buildlink2.mk,v 1.3 2003/07/13 13:51:11 wiz Exp $
#
# This Makefile fragment is included by packages that use gnome-objc.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(GNOME_OBJC_BUILDLINK2_MK)
GNOME_OBJC_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnome-objc
BUILDLINK_DEPENDS.gnome-objc?=		gnome-objc>=1.0.40nb3
BUILDLINK_PKGSRCDIR.gnome-objc?=		../../devel/gnome-objc

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnome-objc=gnome-objc
BUILDLINK_PREFIX.gnome-objc_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gnome-objc+=	include/obgnome/*.h
BUILDLINK_FILES.gnome-objc+=	include/obgtk/*.h
BUILDLINK_FILES.gnome-objc+=	lib/libobgnome.*
BUILDLINK_FILES.gnome-objc+=	lib/libobgtk.*
BUILDLINK_FILES.gnome-objc+=	lib/obGnomeConf.sh

.include "../../x11/gnome-libs/buildlink2.mk"

BUILDLINK_TARGETS+=	gnome-objc-buildlink

gnome-objc-buildlink: _BUILDLINK_USE

.endif	# GNOME_OBJC_BUILDLINK2_MK
