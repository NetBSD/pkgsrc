# $NetBSD: buildlink3.mk,v 1.24 2011/10/11 10:02:08 adam Exp $

BUILDLINK_TREE+=	boost-python

.if !defined(BOOST_PYTHON_BUILDLINK3_MK)
BOOST_PYTHON_BUILDLINK3_MK:=

# Use a dependency pattern that guarantees the proper ABI.
BUILDLINK_API_DEPENDS.boost-python+=	boost-python-1.47.*
BUILDLINK_ABI_DEPENDS.boost-python+=	boost-python-1.47.*
BUILDLINK_PKGSRCDIR.boost-python?=	../../devel/boost-python

.include "../../devel/boost-headers/buildlink3.mk"
.endif # BOOST_PYTHON_BUILDLINK3_MK

BUILDLINK_TREE+=	-boost-python
