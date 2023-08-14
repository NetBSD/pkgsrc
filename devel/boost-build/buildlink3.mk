# $NetBSD: buildlink3.mk,v 1.51 2023/08/14 05:24:04 wiz Exp $

BUILDLINK_TREE+=	boost-build

.if !defined(BOOST_BUILD_BUILDLINK3_MK)
BOOST_BUILD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.boost-build+=	boost-build-1.82.*
BUILDLINK_DEPMETHOD.boost-build?=	build
BUILDLINK_ABI_DEPENDS.boost-build?=	boost-build>=1.82.0nb1
BUILDLINK_PKGSRCDIR.boost-build?=	../../devel/boost-build
.endif # BOOST_BUILD_BUILDLINK3_MK

BUILDLINK_TREE+=	-boost-build
