# $NetBSD: buildlink3.mk,v 1.16 2016/03/05 11:27:54 jperkin Exp $

BUILDLINK_TREE+=	libssh

.if !defined(LIBSSH_BUILDLINK3_MK)
LIBSSH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libssh+=	libssh>=0.54
BUILDLINK_ABI_DEPENDS.libssh+=	libssh>=0.73nb1
BUILDLINK_PKGSRCDIR.libssh?=	../../security/libssh

pkgbase := libssh
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.libssh:Mzlib)
.include "../../devel/zlib/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.libssh:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
.endif
.endif # LIBSSH_BUILDLINK3_MK

BUILDLINK_TREE+=	-libssh
