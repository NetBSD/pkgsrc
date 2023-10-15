# $NetBSD: buildlink3.mk,v 1.1 2023/10/15 07:03:05 ryoon Exp $

BUILDLINK_TREE+=	mdds2.0

.if !defined(MDDS2.0_BUILDLINK3_MK)
MDDS2.0_BUILDLINK3_MK:=

# only contains header files
BUILDLINK_DEPMETHOD.mdds2.0?=	build

USE_CXX_FEATURES+=	c++17

BUILDLINK_API_DEPENDS.mdds2.0+=	mdds2.0>=2.0.1
BUILDLINK_PKGSRCDIR.mdds2.0?=	../../devel/mdds2.0

.endif	# MDDS2.0_BUILDLINK3_MK

BUILDLINK_TREE+=	-mdds2.0
