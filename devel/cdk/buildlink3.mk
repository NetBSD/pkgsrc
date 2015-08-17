# $NetBSD: buildlink3.mk,v 1.9 2015/08/17 17:11:19 wiz Exp $

BUILDLINK_TREE+=	cdk

.if !defined(CDK_BUILDLINK3_MK)
CDK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cdk+=		cdk>=4.9.9nb1
BUILDLINK_ABI_DEPENDS.cdk+=	cdk>=4.9.9nb4
BUILDLINK_PKGSRCDIR.cdk?=	../../devel/cdk

USE_NCURSES=	yes

.include "../../devel/ncurses/buildlink3.mk"
.endif # CDK_BUILDLINK3_MK

BUILDLINK_TREE+=	-cdk
