# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/03/09 16:53:16 sno Exp $
#

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SAPNWRFCSDK_BUILDLINK3_MK:=	${SAPNWRFCSDK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	sapnwrfcsdk
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsapnwrfcsdk}
BUILDLINK_PACKAGES+=	sapnwrfcsdk
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}sapnwrfcsdk

.if !empty(SAPNWRFCSDK_BUILDLINK3_MK:M+)

.  include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_API_DEPENDS.sapnwrfcsdk+=	sapnwrfcsdk>=7.00
BUILDLINK_ABI_DEPENDS.sapnwrfcsdk+=	sapnwrfcsdk>=7.00
BUILDLINK_PKGSRCDIR.sapnwrfcsdk?=	../../devel/sapnwrfcsdk
.endif	# SAPNWRFCSDK_BUILDLINK3_MK
pkgbase := sapnwrfcsdk
.include "../../mk/pkg-build-options.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
