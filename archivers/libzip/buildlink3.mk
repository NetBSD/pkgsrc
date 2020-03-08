# $NetBSD: buildlink3.mk,v 1.20 2020/03/08 16:47:24 wiz Exp $

BUILDLINK_TREE+=	libzip

.if !defined(LIBZIP_BUILDLINK3_MK)
LIBZIP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libzip+=	libzip>=0.7.1
BUILDLINK_ABI_DEPENDS.libzip+=	libzip>=1.6.1nb1
BUILDLINK_PKGSRCDIR.libzip?=	../../archivers/libzip

BUILDLINK_INCDIRS.libzip=	include lib/libzip/include

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.fast.prefs.mk"
pkgbase := libzip
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.libzip:Mgnutls)
.include "../../security/gnutls/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.libzip:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
.endif
.endif # LIBZIP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libzip
