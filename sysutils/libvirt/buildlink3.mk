# $NetBSD: buildlink3.mk,v 1.13 2024/05/16 06:15:34 wiz Exp $

BUILDLINK_TREE+=	libvirt

.if !defined(LIBVIRT_BUILDLINK3_MK)
LIBVIRT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvirt+=	libvirt>=1.2.9nb27
BUILDLINK_ABI_DEPENDS.libvirt?=	libvirt>=1.2.9nb51
BUILDLINK_PKGSRCDIR.libvirt?=	../../sysutils/libvirt

.include "../../devel/yajl/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.fast.prefs.mk"

pkgbase := libvirt
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.libvirt:Mlibssh2}
.include "../../security/libssh2/buildlink3.mk"
.endif
.if ${PKG_BUILD_OPTIONS.libvirt:Mdbus}
.include "../../sysutils/dbus/buildlink3.mk"
.endif
.if ${PKG_BUILD_OPTIONS.libvirt:Mavahi}
.include "../../net/avahi/buildlink3.mk"
.endif

.endif	# LIBVIRT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvirt
