# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:24:11 joerg Exp $

BUILDLINK_TREE+=	cdk

.if !defined(CDK_BUILDLINK3_MK)
CDK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cdk+=		cdk>=4.9.9nb1
BUILDLINK_ABI_DEPENDS.cdk+=	cdk>=4.9.9nb2
BUILDLINK_PKGSRCDIR.cdk?=	../../devel/cdk

USE_NCURSES=	yes

.include "../../devel/ncurses/buildlink3.mk"
.endif # CDK_BUILDLINK3_MK

BUILDLINK_TREE+=	-cdk
