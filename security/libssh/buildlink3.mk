# $NetBSD: buildlink3.mk,v 1.15 2016/02/23 15:49:30 wiz Exp $

BUILDLINK_TREE+=	libssh

.if !defined(LIBSSH_BUILDLINK3_MK)
LIBSSH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libssh+=	libssh>=0.54
BUILDLINK_ABI_DEPENDS.libssh+=	libssh>=0.54nb3
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
