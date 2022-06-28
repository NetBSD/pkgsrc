# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:33:42 wiz Exp $

BUILDLINK_TREE+=	rinutils

.if !defined(RINUTILS_BUILDLINK3_MK)
RINUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rinutils+=	rinutils>=0.8.0
BUILDLINK_ABI_DEPENDS.rinutils?=		rinutils>=0.8.0nb2
BUILDLINK_PKGSRCDIR.rinutils?=		../../devel/rinutils

BUILDLINK_DEPMETHOD.rinutils?=		build
.endif	# RINUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-rinutils
