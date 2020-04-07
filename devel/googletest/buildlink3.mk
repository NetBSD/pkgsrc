# $NetBSD: buildlink3.mk,v 1.2 2020/04/07 21:36:58 adam Exp $

BUILDLINK_TREE+=	googletest

.if !defined(GOOGLETEST_BUILDLINK3_MK)
GOOGLETEST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.googletest+=	googletest>=1.4.0
BUILDLINK_DEPMETHOD.googletest?=	build
BUILDLINK_PKGSRCDIR.googletest?=	../../devel/googletest
.endif	# GOOGLETEST_BUILDLINK3_MK

BUILDLINK_TREE+=	-googletest
