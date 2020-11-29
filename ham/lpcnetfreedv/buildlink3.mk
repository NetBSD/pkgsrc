# $NetBSD: buildlink3.mk,v 1.1 2020/11/29 23:12:43 dbj Exp $

BUILDLINK_TREE+=	lpcnetfreedv

.if !defined(LPCNETFREEDV_BUILDLINK3_MK)
LPCNETFREEDV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lpcnetfreedv+=	lpcnetfreedv>=0.2
BUILDLINK_PKGSRCDIR.lpcnetfreedv?=	../../ham/lpcnetfreedv

BUILDLINK_INCDIRS.lpcnetfreedv+=	include/lpcnet

.endif	# LPCNETFREEDV_BUILDLINK3_MK

BUILDLINK_TREE+=	-lpcnetfreedv
