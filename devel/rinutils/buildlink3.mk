# $NetBSD: buildlink3.mk,v 1.3 2023/03/16 08:06:13 adam Exp $

BUILDLINK_TREE+=	rinutils

.if !defined(RINUTILS_BUILDLINK3_MK)
RINUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rinutils+=	rinutils>=0.8.0
BUILDLINK_ABI_DEPENDS.rinutils+=	rinutils>=0.8.0nb2
BUILDLINK_PKGSRCDIR.rinutils?=		../../devel/rinutils

BUILDLINK_DEPMETHOD.rinutils?=		build
.endif	# RINUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-rinutils
