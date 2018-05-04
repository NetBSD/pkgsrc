# $NetBSD: buildlink3.mk,v 1.1 2018/05/04 14:28:32 fhajny Exp $

BUILDLINK_TREE+=	nodejs

.if !defined(NODEJS_BUILDLINK3_MK)
NODEJS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nodejs+=	nodejs>=6<7
BUILDLINK_PKGSRCDIR.nodejs?=	../../lang/nodejs6

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
.include "../../devel/libexecinfo/buildlink3.mk"
.endif
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

pkgbase := nodejs
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.nodejs:Mopenssl)
.  include "../../security/openssl/buildlink3.mk"
.endif

.endif # NODEJS_BUILDLINK3_MK

BUILDLINK_TREE+=	-nodejs
