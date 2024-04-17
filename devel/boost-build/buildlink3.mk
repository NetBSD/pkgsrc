# $NetBSD: buildlink3.mk,v 1.54 2024/04/17 16:14:01 adam Exp $

BUILDLINK_TREE+=	boost-build

.if !defined(BOOST_BUILD_BUILDLINK3_MK)
BOOST_BUILD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.boost-build+=	boost-build-1.85.*
BUILDLINK_DEPMETHOD.boost-build?=	build
BUILDLINK_ABI_DEPENDS.boost-build+=	boost-build>=1.85.0
BUILDLINK_PKGSRCDIR.boost-build?=	../../devel/boost-build
.endif # BOOST_BUILD_BUILDLINK3_MK

BUILDLINK_TREE+=	-boost-build
