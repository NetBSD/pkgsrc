# $NetBSD: buildlink3.mk,v 1.1 2022/12/17 14:34:13 mef Exp $

BUILDLINK_TREE+=	R-systemfonts

.if !defined(R_SYSTEMFONTS_BUILDLINK3_MK)
R_SYSTEMFONTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.R-systemfonts+=	R-systemfonts>=1.0.0
BUILDLINK_PKGSRCDIR.R-systemfonts?=	../../fonts/R-systemfonts
.endif	# R_SYSTEMFONTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-R-systemfonts
