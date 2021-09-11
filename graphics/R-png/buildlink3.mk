# $NetBSD: buildlink3.mk,v 1.1 2021/09/11 12:05:57 mef Exp $

BUILDLINK_TREE+=	R-png

.if !defined(R_PNG_BUILDLINK3_MK)
R_PNG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.R-png+=	R-png>=0.1.7
BUILDLINK_PKGSRCDIR.R-png?=	../../graphics/R-png
.endif	# R_PNG_BUILDLINK3_MK

BUILDLINK_TREE+=	-R-png
