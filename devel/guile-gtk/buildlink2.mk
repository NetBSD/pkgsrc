# $NetBSD: buildlink2.mk,v 1.3 2003/05/02 11:54:31 wiz Exp $

.if !defined(GUILE_GTK_BUILDLINK2_MK)
GUILE_GTK_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		guile-gtk
BUILDLINK_DEPENDS.guile-gtk?=	guile-gtk>=0.19nb2
BUILDLINK_PKGSRCDIR.guile-gtk?=	../../devel/guile-gtk

EVAL_PREFIX+=	BUILDLINK_PREFIX.guile-gtk=guile-gtk
BUILDLINK_PREFIX.guile-gtk_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.guile-gtk+=	include/guile-gtk.h
BUILDLINK_FILES.guile-gtk+=	lib/libguilegtk-1.2.*

.include "../../lang/guile14/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

BUILDLINK_TARGETS+=	guile-gtk-buildlink

guile-gtk-buildlink: _BUILDLINK_USE

.endif	# GUILE_GTK_BUILDLINK2_MK
