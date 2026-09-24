# $NetBSD: buildlink3.mk,v 1.1 2026/09/24 16:08:26 ktnb Exp $

BUILDLINK_TREE+=	doctest

.if !defined(DOCTEST_BUILDLINK3_MK)
DOCTEST_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.doctest?=	build

BUILDLINK_API_DEPENDS.doctest+=	doctest>=2.5.3
BUILDLINK_PKGSRCDIR.doctest?=	../../devel/doctest
.endif	# DOCTEST_BUILDLINK3_MK

BUILDLINK_TREE+=	-doctest
