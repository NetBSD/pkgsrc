# $NetBSD: buildlink3.mk,v 1.24 2012/07/02 13:37:36 adam Exp $

BUILDLINK_TREE+=	boost-libs

.if !defined(BOOST_LIBS_BUILDLINK3_MK)
BOOST_LIBS_BUILDLINK3_MK:=

# Use a dependency pattern that guarantees the proper ABI.
BUILDLINK_API_DEPENDS.boost-libs+=	boost-libs-1.50.*
BUILDLINK_ABI_DEPENDS.boost-libs?=	boost-libs>=1.50.0
BUILDLINK_PKGSRCDIR.boost-libs?=	../../devel/boost-libs

.include "../../devel/boost-headers/buildlink3.mk"
.endif # BOOST_LIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-boost-libs
