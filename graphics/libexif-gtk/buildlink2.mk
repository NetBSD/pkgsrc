# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/12/24 21:30:35 wiz Exp $
#

.if !defined(LIBEXIF_GTK_BUILDLINK2_MK)
LIBEXIF_GTK_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libexif-gtk
BUILDLINK_DEPENDS.libexif-gtk?=		libexif-gtk>=0.3.2
BUILDLINK_PKGSRCDIR.libexif-gtk?=	../../graphics/libexif-gtk

EVAL_PREFIX+=	BUILDLINK_PREFIX.libexif-gtk=libexif-gtk
BUILDLINK_PREFIX.libexif-gtk_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libexif-gtk+=	include/libexif-gtk/*.h
BUILDLINK_FILES.libexif-gtk+=	lib/libexif-gtk.*

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/libexif/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	libexif-gtk-buildlink

libexif-gtk-buildlink: _BUILDLINK_USE

.endif	# LIBEXIF_GTK_BUILDLINK2_MK
