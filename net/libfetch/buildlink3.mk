# $NetBSD: buildlink3.mk,v 1.16 2023/10/24 22:10:22 wiz Exp $

BUILDLINK_TREE+=	libfetch

.if !defined(LIBFETCH_BUILDLINK3_MK)
LIBFETCH_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.libfetch?=	build

BUILDLINK_API_DEPENDS.libfetch+=	libfetch>=2.28
BUILDLINK_ABI_DEPENDS.libfetch?=	libfetch>=2.39nb2
BUILDLINK_PKGSRCDIR.libfetch?=		../../net/libfetch

pkgbase := libfetch
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.libfetch:Mopenssl)
.  include "../../security/openssl/buildlink3.mk"
BUILDLINK_LIBS.libfetch+=	-lcrypto -lssl
.endif
.endif # LIBFETCH_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfetch
