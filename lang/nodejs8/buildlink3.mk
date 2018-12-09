# $NetBSD: buildlink3.mk,v 1.4 2018/12/09 18:52:03 adam Exp $

BUILDLINK_TREE+=	nodejs

.if !defined(NODEJS_BUILDLINK3_MK)
NODEJS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nodejs+=	nodejs>=8<9
BUILDLINK_ABI_DEPENDS.nodejs?=	nodejs>=8.12.0nb1
BUILDLINK_PKGSRCDIR.nodejs?=	../../lang/nodejs8

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
.include "../../devel/libexecinfo/buildlink3.mk"
.endif
.include "../../devel/libuv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../www/http-parser/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

pkgbase := nodejs
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.nodejs:Mopenssl)
.  include "../../security/openssl/buildlink3.mk"
.endif

.endif # NODEJS_BUILDLINK3_MK

BUILDLINK_TREE+=	-nodejs
