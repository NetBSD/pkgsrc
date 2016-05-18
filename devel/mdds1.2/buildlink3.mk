# $NetBSD: buildlink3.mk,v 1.1 2016/05/18 11:48:45 wiz Exp $

BUILDLINK_TREE+=	mdds1.2

.if !defined(MDDS12_BUILDLINK3_MK)
MDDS12_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mdds1.2+=	mdds1.2>=1.2.0
BUILDLINK_PKGSRCDIR.mdds1.2?=	../../devel/mdds1.2

# only contains header files
BUILDLINK_DEPMETHOD.mdds1.2?=	build

.include "../../devel/boost-headers/buildlink3.mk"
.endif	# MDDS12_BUILDLINK3_MK

BUILDLINK_TREE+=	-mdds1.2
