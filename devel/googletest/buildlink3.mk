# $NetBSD: buildlink3.mk,v 1.5 2026/08/16 12:11:59 wiz Exp $

BUILDLINK_TREE+=	googletest

.if !defined(GOOGLETEST_BUILDLINK3_MK)
GOOGLETEST_BUILDLINK3_MK:=

USE_CXX_FEATURES+=		c++17

BUILDLINK_API_DEPENDS.googletest+=	googletest>=1.4.0
BUILDLINK_DEPMETHOD.googletest?=	build
BUILDLINK_PKGSRCDIR.googletest?=	../../devel/googletest

.endif	# GOOGLETEST_BUILDLINK3_MK

BUILDLINK_TREE+=	-googletest
