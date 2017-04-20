# $NetBSD: buildlink3.mk,v 1.10 2017/04/20 08:39:03 jperkin Exp $

BUILDLINK_TREE+=	cppunit

.if !defined(CPPUNIT_BUILDLINK3_MK)
CPPUNIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cppunit+=	cppunit>=1.10.2
BUILDLINK_ABI_DEPENDS.cppunit+=	cppunit>=1.10.2nb5
BUILDLINK_PKGSRCDIR.cppunit?=	../../devel/cppunit
BUILDLINK_CPPFLAGS.cppunit+=	-I${BUILDLINK_PREFIX.cppunit}/include/cppunit
.endif # CPPUNIT_BUILDLINK3_MK

# cppunit enables C++11 so all dependencies must be built the same way
CXXFLAGS+=		-std=c++11

BUILDLINK_TREE+=	-cppunit
