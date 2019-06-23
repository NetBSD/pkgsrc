# $NetBSD: buildlink3.mk,v 1.1 2019/06/23 09:40:54 wiz Exp $

BUILDLINK_TREE+=	unittest-cpp

.if !defined(UNITTEST_CPP_BUILDLINK3_MK)
UNITTEST_CPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.unittest-cpp+=	unittest-cpp>=2.0.0
BUILDLINK_PKGSRCDIR.unittest-cpp?=	../../devel/unittest-cpp
.endif	# UNITTEST_CPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-unittest-cpp
