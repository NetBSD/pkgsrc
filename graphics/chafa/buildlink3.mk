# $NetBSD: buildlink3.mk,v 1.1 2024/10/09 14:05:56 ktnb Exp $

BUILDLINK_TREE+=	chafa

.if !defined(CHAFA_BUILDLINK3_MK)
CHAFA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.chafa+=	chafa>=1.14.4
BUILDLINK_PKGSRCDIR.chafa?=	../../graphics/chafa

.endif	# CHAFA_BUILDLINK3_MK

BUILDLINK_TREE+=	-chafa
