# $NetBSD: buildlink3.mk,v 1.1 2022/12/17 14:53:22 mef Exp $

BUILDLINK_TREE+=	R-textshaping

.if !defined(R_TEXTSHAPING_BUILDLINK3_MK)
R_TEXTSHAPING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.R-textshaping+=	R-textshaping>=0.3.6
BUILDLINK_PKGSRCDIR.R-textshaping?=	../../fonts/R-textshaping
.endif	# R_TEXTSHAPING_BUILDLINK3_MK

BUILDLINK_TREE+=	-R-textshaping
