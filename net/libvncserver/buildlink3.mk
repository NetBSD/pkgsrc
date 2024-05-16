# $NetBSD: buildlink3.mk,v 1.31 2024/05/16 06:15:21 wiz Exp $

BUILDLINK_TREE+=	libVNCServer

.if !defined(LIBVNCSERVER_BUILDLINK3_MK)
LIBVNCSERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libVNCServer+=	libVNCServer>=0.9.12
BUILDLINK_ABI_DEPENDS.libVNCServer+=	libVNCServer>=0.9.13nb9
BUILDLINK_PKGSRCDIR.libVNCServer?=	../../net/libvncserver

.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"

pkgbase := libVNCServer
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.libVNCServer:Mgnutls}
.include "../../security/gnutls/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.libVNCServer:Mlibgcrypt}
.include "../../security/libgcrypt/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.libVNCServer:Mopenssl}
.include "../../security/openssl/buildlink3.mk"
.endif

.if  ${PKG_BUILD_OPTIONS.libVNCServer:Msasl}
.include "../../security/cyrus-sasl/buildlink3.mk"
.endif

.endif # LIBVNCSERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libVNCServer
