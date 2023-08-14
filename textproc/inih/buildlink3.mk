# $NetBSD: buildlink3.mk,v 1.2 2023/08/14 05:25:22 wiz Exp $

BUILDLINK_TREE+=	inih

.if !defined(INIH_BUILDLINK3_MK)
INIH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.inih+=	inih>=52
BUILDLINK_ABI_DEPENDS.inih?=	inih>=53nb1
BUILDLINK_PKGSRCDIR.inih?=	../../textproc/inih
.endif	# INIH_BUILDLINK3_MK

BUILDLINK_TREE+=	-inih
