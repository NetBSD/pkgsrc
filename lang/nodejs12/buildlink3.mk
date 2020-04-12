# $NetBSD: buildlink3.mk,v 1.4 2020/04/12 08:27:58 adam Exp $

BUILDLINK_TREE+=	nodejs

.if !defined(NODEJS_BUILDLINK3_MK)
NODEJS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nodejs+=	nodejs>=10
BUILDLINK_ABI_DEPENDS.nodejs+=	nodejs>=12.16.1nb1
BUILDLINK_PKGSRCDIR.nodejs?=	../../lang/nodejs

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Darwin"
.include "../../devel/libexecinfo/buildlink3.mk"
.endif
# Stated by the changelog
BUILDLINK_API_DEPENDS.libuv+=	libuv>=1.23
.include "../../devel/libuv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../www/nghttp2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

pkgbase := nodejs
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.nodejs:Mopenssl)
.  include "../../security/openssl/buildlink3.mk"
.endif

.endif # NODEJS_BUILDLINK3_MK

BUILDLINK_TREE+=	-nodejs
