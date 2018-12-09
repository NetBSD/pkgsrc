# $NetBSD: buildlink3.mk,v 1.18 2018/12/09 18:52:06 adam Exp $

BUILDLINK_TREE+=	libzrtpcpp

.if !defined(LIBZRTPCPP_BUILDLINK3_MK)
LIBZRTPCPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libzrtpcpp+=	libzrtpcpp>=4.4.0
BUILDLINK_ABI_DEPENDS.libzrtpcpp?=	libzrtpcpp>=4.4.0nb13
BUILDLINK_PKGSRCDIR.libzrtpcpp?=	../../net/libzrtpcpp

pkgbase := libzrtpcpp
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.libzrtpcpp:Msqlite3)
.include "../../databases/sqlite3/buildlink3.mk"
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../net/ccrtp/buildlink3.mk"
.endif # LIBZRTPCPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libzrtpcpp
