# $NetBSD: buildlink3.mk,v 1.1 2020/07/13 18:50:29 wiz Exp $

BUILDLINK_TREE+=	ups-nut

.if !defined(UPS_NUT_BUILDLINK3_MK)
UPS_NUT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ups-nut+=	ups-nut>=2.7.4
BUILDLINK_PKGSRCDIR.ups-nut?=	../../sysutils/ups-nut

.include "../../mk/pthread.buildlink3.mk"
.endif	# UPS_NUT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ups-nut
