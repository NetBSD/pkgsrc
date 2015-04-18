# $NetBSD: buildlink3.mk,v 1.5 2015/04/18 02:43:24 rodent Exp $

BUILDLINK_TREE+=	ucommon

.if !defined(UCOMMON_BUILDLINK3_MK)
UCOMMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ucommon+=	ucommon>=6.0.0
BUILDLINK_ABI_DEPENDS.ucommon?=	ucommon>=6.3.1
BUILDLINK_PKGSRCDIR.ucommon?=	../../devel/ucommon

pkgbase := ucommon
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.ucommon:Mgnutls)
BUILDLINK_API_DEPENDS.gnutls+=	gnutls>=3.0.0
.include "../../security/gnutls/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ucommon:Mopenssl)
BUILDLINK_API_DEPENDS.openssl+=	openssl>=1.0.0
.include "../../security/openssl/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ucommon:Mstatic)
BUILDLINK_DEPMETHOD.ucommon?=	build
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # UCOMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-ucommon
