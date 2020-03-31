# $NetBSD: buildlink3.mk,v 1.1 2020/03/31 10:03:35 nia Exp $

BUILDLINK_TREE+=	tl-expected

.if !defined(TL_EXPECTED_BUILDLINK3_MK)
TL_EXPECTED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tl-expected+=	tl-expected>=1.0.0
BUILDLINK_PKGSRCDIR.tl-expected?=	../../devel/tl-expected
# Only installs headers.
BUILDLINK_DEPMETHOD.tl-expected?=	build
.endif	# TL_EXPECTED_BUILDLINK3_MK

BUILDLINK_TREE+=	-tl-expected
