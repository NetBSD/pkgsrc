# $NetBSD: buildlink3.mk,v 1.1 2025/08/17 09:37:52 bsiegert Exp $

BUILDLINK_TREE+=	lerc

.if !defined(LERC_BUILDLINK3_MK)
LERC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lerc+=	lerc>=4.0.0
BUILDLINK_PKGSRCDIR.lerc?=	../../graphics/lerc
.endif	# LERC_BUILDLINK3_MK

BUILDLINK_TREE+=	-lerc
