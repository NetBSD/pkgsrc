# $NetBSD: buildlink3.mk,v 1.12 2024/05/06 08:33:49 jperkin Exp $

BUILDLINK_TREE+=	cdk

.if !defined(CDK_BUILDLINK3_MK)
CDK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cdk+=	cdk>=4.9.9nb1
BUILDLINK_ABI_DEPENDS.cdk+=	cdk>=4.9.9nb5
BUILDLINK_PKGSRCDIR.cdk?=	../../devel/cdk

.include "../../devel/ncurses/buildlink3.mk"
.endif # CDK_BUILDLINK3_MK

BUILDLINK_TREE+=	-cdk
