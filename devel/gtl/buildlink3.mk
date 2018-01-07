# $NetBSD: buildlink3.mk,v 1.9 2018/01/07 13:04:03 rillig Exp $

BUILDLINK_TREE+=	gtl

.if !defined(GTL_BUILDLINK3_MK)
GTL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtl+=	gtl>=1.2.0
BUILDLINK_PKGSRCDIR.gtl?=	../../devel/gtl
.endif # GTL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtl
