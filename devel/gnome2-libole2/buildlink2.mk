# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/11/04 03:53:02 rh Exp $
#
# This Makefile fragment is included by packages that use gnome2-libole2.
#
# This file was created automatically using createbuildlink 2.2.
#

.if !defined(GNOME2_LIBOLE2_BUILDLINK2_MK)
GNOME2_LIBOLE2_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnome2-libole2
BUILDLINK_DEPENDS.gnome2-libole2?=		gnome2-libole2>=2.2.8
BUILDLINK_PKGSRCDIR.gnome2-libole2?=		../../devel/gnome2-libole2

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnome2-libole2=gnome2-libole2
BUILDLINK_PREFIX.gnome2-libole2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gnome2-libole2+=	include/libole2-2.0/libole2/*.h
BUILDLINK_FILES.gnome2-libole2+=	lib/libgnome2ole2.*
BUILDLINK_FILES.gnome2-libole2+=	lib/pkgconfig/libole2-2.0.pc

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"

BUILDLINK_TARGETS+=	gnome2-libole2-buildlink

gnome2-libole2-buildlink: _BUILDLINK_USE

.endif	# GNOME2_LIBOLE2_BUILDLINK2_MK
