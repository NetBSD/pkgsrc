# $NetBSD: buildlink3.mk,v 1.26.10.1 2026/08/05 14:31:37 maya Exp $

BUILDLINK_TREE+=	libssh

.if !defined(LIBSSH_BUILDLINK3_MK)
LIBSSH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libssh+=	libssh>=0.11.5<0.100
BUILDLINK_ABI_DEPENDS.libssh?=	libssh>=0.11.5
BUILDLINK_PKGSRCDIR.libssh?=	../../security/libssh

pkgbase := libssh
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.libssh:Mgssapi}
.include "../../mk/krb5.buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.libssh:Mopenssl}
.include "../../security/openssl/buildlink3.mk"
.endif

.include "../../devel/zlib/buildlink3.mk"
.endif # LIBSSH_BUILDLINK3_MK

BUILDLINK_TREE+=	-libssh
