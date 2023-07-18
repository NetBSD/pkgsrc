# $NetBSD: buildlink3.mk,v 1.14 2023/07/18 14:11:14 nia Exp $

BUILDLINK_TREE+=	cppunit

.if !defined(CPPUNIT_BUILDLINK3_MK)
CPPUNIT_BUILDLINK3_MK:=

USE_CXX_FEATURES+=	c++11

BUILDLINK_API_DEPENDS.cppunit+=	cppunit>=1.10.2
BUILDLINK_ABI_DEPENDS.cppunit+=	cppunit>=1.10.2nb5
BUILDLINK_PKGSRCDIR.cppunit?=	../../devel/cppunit
BUILDLINK_CPPFLAGS.cppunit+=	-I${BUILDLINK_PREFIX.cppunit}/include/cppunit
.endif # CPPUNIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-cppunit
