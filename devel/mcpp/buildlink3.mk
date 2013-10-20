# $NetBSD: buildlink3.mk,v 1.1 2013/10/20 15:06:58 ryoon Exp $

BUILDLINK_TREE+=	mcpp

.if !defined(MCPP_BUILDLINK3_MK)
MCPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mcpp+=	mcpp>=2.7.2
BUILDLINK_PKGSRCDIR.mcpp?=	../../devel/mcpp
.endif	# MCPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-mcpp
