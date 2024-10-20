# $NetBSD: buildlink3.mk,v 1.66 2024/10/20 14:04:25 wiz Exp $

BUILDLINK_TREE+=	gtk-vnc

.if !defined(GTK_VNC_BUILDLINK3_MK)
GTK_VNC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtk-vnc+=	gtk-vnc>=0.5.1
BUILDLINK_ABI_DEPENDS.gtk-vnc+=	gtk-vnc>=1.3.1nb4
BUILDLINK_PKGSRCDIR.gtk-vnc?=	../../net/gtk-vnc

pkgbase := gtk-vnc
.include "../../mk/pkg-build-options.mk"
.if ${PKG_BUILD_OPTIONS.gtk-vnc:Msasl}
.include "../../security/cyrus-sasl/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.gtk-vnc:Mpulseaudio}
.include "../../audio/pulseaudio/buildlink3.mk"
.endif

.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.11
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif # GTK_VNC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtk-vnc
