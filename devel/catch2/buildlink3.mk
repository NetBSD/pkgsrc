# $NetBSD: buildlink3.mk,v 1.3 2024/01/15 09:33:46 nros Exp $

BUILDLINK_TREE+=	catch2

.if !defined(CATCH2_BUILDLINK3_MK)
CATCH2_BUILDLINK3_MK:=

USE_CXX_FEATURES+=	c++14

BUILDLINK_DEPMETHOD.catch2?=	build
BUILDLINK_API_DEPENDS.catch2+=	catch2>=3.5.1
BUILDLINK_PKGSRCDIR.catch2?=	../../devel/catch2
.endif	# CATCH2_BUILDLINK3_MK

BUILDLINK_TREE+=	-catch2
