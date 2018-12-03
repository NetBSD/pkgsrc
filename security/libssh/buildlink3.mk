# $NetBSD: buildlink3.mk,v 1.18 2018/12/03 15:19:51 adam Exp $

BUILDLINK_TREE+=	libssh

.if !defined(LIBSSH_BUILDLINK3_MK)
LIBSSH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libssh+=	libssh>=0.54
BUILDLINK_ABI_DEPENDS.libssh+=	libssh>=0.73nb1
BUILDLINK_PKGSRCDIR.libssh?=	../../security/libssh

pkgbase := libssh
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.libssh:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
.endif

.include "../../devel/argp/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.endif # LIBSSH_BUILDLINK3_MK

BUILDLINK_TREE+=	-libssh
