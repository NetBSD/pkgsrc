# $NetBSD: buildlink3.mk,v 1.15 2010/05/15 05:42:23 adam Exp $

BUILDLINK_TREE+=	boost-build

.if !defined(BOOST_BUILD_BUILDLINK3_MK)
BOOST_BUILD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.boost-build+=	boost-build-1.43.*
BUILDLINK_DEPMETHOD.boost-build?=	build
BUILDLINK_PKGSRCDIR.boost-build?=	../../devel/boost-build
.endif # BOOST_BUILD_BUILDLINK3_MK

BUILDLINK_TREE+=	-boost-build
