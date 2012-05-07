# $NetBSD: buildlink3.mk,v 1.9 2012/05/07 01:53:20 dholland Exp $

BUILDLINK_TREE+=	cppunit

.if !defined(CPPUNIT_BUILDLINK3_MK)
CPPUNIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cppunit+=	cppunit>=1.10.2
BUILDLINK_ABI_DEPENDS.cppunit+=	cppunit>=1.10.2nb5
BUILDLINK_PKGSRCDIR.cppunit?=	../../devel/cppunit
BUILDLINK_CPPFLAGS.cppunit+=	-I${BUILDLINK_PREFIX.cppunit}/include/cppunit
.endif # CPPUNIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-cppunit
