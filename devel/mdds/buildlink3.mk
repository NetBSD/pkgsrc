# $NetBSD: buildlink3.mk,v 1.8 2023/10/15 07:18:52 ryoon Exp $

BUILDLINK_TREE+=	mdds

.if !defined(MDDS_BUILDLINK3_MK)
MDDS_BUILDLINK3_MK:=

USE_CXX_FEATURES+=	c++17

BUILDLINK_API_DEPENDS.mdds+=	mdds>=2.1.1
BUILDLINK_PKGSRCDIR.mdds?=	../../devel/mdds
# only contains header files
BUILDLINK_DEPMETHOD.mdds?=	build

.include "../../devel/boost-headers/buildlink3.mk"
.endif	# MDDS_BUILDLINK3_MK

BUILDLINK_TREE+=	-mdds
