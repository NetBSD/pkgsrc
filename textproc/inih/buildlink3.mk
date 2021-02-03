# $NetBSD: buildlink3.mk,v 1.1 2021/02/03 10:28:41 nia Exp $

BUILDLINK_TREE+=	inih

.if !defined(INIH_BUILDLINK3_MK)
INIH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.inih+=	inih>=52
BUILDLINK_PKGSRCDIR.inih?=	../../textproc/inih
.endif	# INIH_BUILDLINK3_MK

BUILDLINK_TREE+=	-inih
