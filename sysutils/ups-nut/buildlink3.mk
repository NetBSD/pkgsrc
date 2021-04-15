# $NetBSD: buildlink3.mk,v 1.5 2021/04/15 11:23:04 ryoon Exp $

BUILDLINK_TREE+=	ups-nut

.if !defined(UPS_NUT_BUILDLINK3_MK)
UPS_NUT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ups-nut+=	ups-nut>=2.7.4
BUILDLINK_ABI_DEPENDS.ups-nut?=	ups-nut>=2.7.4nb6
BUILDLINK_PKGSRCDIR.ups-nut?=	../../sysutils/ups-nut

pkgbase:= ups-nut
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.ups-nut:Mnss}
.  include "../../devel/nss/buildlink3.mk"
#.elif ${PKG_BUILD_OPTIONS.ups-nut:Mopenssl}
#.  include "../../security/openssl/buildlink3.mk"
.endif

.include "../../mk/pthread.buildlink3.mk"
.endif	# UPS_NUT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ups-nut
