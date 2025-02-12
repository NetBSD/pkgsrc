# $NetBSD: buildlink3.mk,v 1.1 2025/02/12 21:05:50 wiz Exp $

BUILDLINK_TREE+=	pstoedit

.if !defined(PSTOEDIT_BUILDLINK3_MK)
PSTOEDIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pstoedit+=	pstoedit>=3.78nb26
BUILDLINK_PKGSRCDIR.pstoedit?=		../../graphics/pstoedit

.endif	# PSTOEDIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-pstoedit
