# $NetBSD: buildlink3.mk,v 1.7 2023/07/19 14:53:20 nia Exp $

BUILDLINK_TREE+=	mdds

.if !defined(MDDS_BUILDLINK3_MK)
MDDS_BUILDLINK3_MK:=

USE_CXX_FEATURES+=	c++17

BUILDLINK_API_DEPENDS.mdds+=	mdds>=2.0.1
BUILDLINK_PKGSRCDIR.mdds?=	../../devel/mdds
# only contains header files
BUILDLINK_DEPMETHOD.mdds?=	build

.include "../../devel/boost-headers/buildlink3.mk"
.endif	# MDDS_BUILDLINK3_MK

BUILDLINK_TREE+=	-mdds
