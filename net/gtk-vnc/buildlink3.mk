# $NetBSD: buildlink3.mk,v 1.11 2011/11/01 06:02:18 sbd Exp $

BUILDLINK_TREE+=	gtk-vnc

.if !defined(GTK_VNC_BUILDLINK3_MK)
GTK_VNC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtk-vnc+=	gtk-vnc>=0.3.7
BUILDLINK_ABI_DEPENDS.gtk-vnc?=	gtk-vnc>=0.3.10nb7
BUILDLINK_PKGSRCDIR.gtk-vnc?=	../../net/gtk-vnc

pkgbase := gtk-vnc
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.gtk-vnc:Mvnc-sasl)
.include "../../security/cyrus-sasl/buildlink3.mk"
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # GTK_VNC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtk-vnc
