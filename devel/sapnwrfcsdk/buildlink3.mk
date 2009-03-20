# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:29 joerg Exp $
#

BUILDLINK_TREE+=	sapnwrfcsdk

.if !defined(SAPNWRFCSDK_BUILDLINK3_MK)
SAPNWRFCSDK_BUILDLINK3_MK:=

.  include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_API_DEPENDS.sapnwrfcsdk+=	sapnwrfcsdk>=7.00
BUILDLINK_ABI_DEPENDS.sapnwrfcsdk+=	sapnwrfcsdk>=7.00
BUILDLINK_PKGSRCDIR.sapnwrfcsdk?=	../../devel/sapnwrfcsdk
pkgbase := sapnwrfcsdk
.include "../../mk/pkg-build-options.mk"
.endif # SAPNWRFCSDK_BUILDLINK3_MK

BUILDLINK_TREE+=	-sapnwrfcsdk
