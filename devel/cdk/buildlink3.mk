# $NetBSD: buildlink3.mk,v 1.13 2024/05/06 08:40:22 jperkin Exp $

BUILDLINK_TREE+=	cdk

.if !defined(CDK_BUILDLINK3_MK)
CDK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cdk+=	cdk>=4.9.9nb1
BUILDLINK_ABI_DEPENDS.cdk+=	cdk>=5.0.20210324nb1
BUILDLINK_PKGSRCDIR.cdk?=	../../devel/cdk

.include "../../devel/ncurses/buildlink3.mk"
.endif # CDK_BUILDLINK3_MK

BUILDLINK_TREE+=	-cdk
