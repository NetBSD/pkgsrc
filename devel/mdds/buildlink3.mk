# $NetBSD: buildlink3.mk,v 1.4 2016/02/13 08:40:22 wiz Exp $

BUILDLINK_TREE+=	mdds

.if !defined(MDDS_BUILDLINK3_MK)
MDDS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mdds+=	mdds>=1.0.0
BUILDLINK_PKGSRCDIR.mdds?=	../../devel/mdds
# only contains header files
BUILDLINK_DEPMETHOD.mdds?=	build

.include "../../devel/boost-headers/buildlink3.mk"
.endif	# MDDS_BUILDLINK3_MK

BUILDLINK_TREE+=	-mdds
