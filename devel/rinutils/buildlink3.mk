# $NetBSD: buildlink3.mk,v 1.1 2021/04/08 19:45:30 markd Exp $

BUILDLINK_TREE+=	rinutils

.if !defined(RINUTILS_BUILDLINK3_MK)
RINUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rinutils+=	rinutils>=0.8.0
BUILDLINK_PKGSRCDIR.rinutils?=		../../devel/rinutils

BUILDLINK_DEPMETHOD.rinutils?=		build
.endif	# RINUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-rinutils
