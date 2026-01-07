# $NetBSD: buildlink3.mk,v 1.26 2026/01/07 08:48:13 wiz Exp $

BUILDLINK_TREE+=	ccrtp

.if !defined(CCRTP_BUILDLINK3_MK)
CCRTP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ccrtp+=	ccrtp>=2.0.0
BUILDLINK_ABI_DEPENDS.ccrtp?=	ccrtp>=2.1.2nb23
BUILDLINK_PKGSRCDIR.ccrtp?=	../../net/ccrtp

pkgbase := ccrtp
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.ccrtp:Mlibgcrypt}
.include "../../security/libgcrypt/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ccrtp:Mopenssl}
.include "../../security/openssl/buildlink3.mk"
.endif

.include "../../devel/ucommon/buildlink3.mk"
.endif # CCRTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ccrtp
