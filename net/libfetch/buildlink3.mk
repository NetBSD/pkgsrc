# $NetBSD: buildlink3.mk,v 1.13 2016/03/05 11:27:52 jperkin Exp $

BUILDLINK_TREE+=	libfetch

.if !defined(LIBFETCH_BUILDLINK3_MK)
LIBFETCH_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.libfetch?=	build

BUILDLINK_API_DEPENDS.libfetch+=	libfetch>=2.28
BUILDLINK_ABI_DEPENDS.libfetch?=	libfetch>=2.36nb3
BUILDLINK_PKGSRCDIR.libfetch?=	../../net/libfetch

pkgbase := libfetch
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.libfetch:Mopenssl)
.  include "../../security/openssl/buildlink3.mk"
BUILDLINK_LIBS.libfetch+=	-lcrypto -lssl
.endif
.endif # LIBFETCH_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfetch
