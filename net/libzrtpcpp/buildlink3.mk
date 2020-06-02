# $NetBSD: buildlink3.mk,v 1.25 2020/06/02 08:22:53 adam Exp $

BUILDLINK_TREE+=	libzrtpcpp

.if !defined(LIBZRTPCPP_BUILDLINK3_MK)
LIBZRTPCPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libzrtpcpp+=	libzrtpcpp>=4.4.0
BUILDLINK_ABI_DEPENDS.libzrtpcpp?=	libzrtpcpp>=4.4.0nb20
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
