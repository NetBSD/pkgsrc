# $NetBSD: buildlink3.mk,v 1.1 2019/08/09 20:24:22 brook Exp $

BUILDLINK_TREE+=	R-later

.if !defined(R_LATER_BUILDLINK3_MK)
R_LATER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.R-later+=	R-later>=0.8.0
BUILDLINK_PKGSRCDIR.R-later?=	../../sysutils/R-later

.endif	# R_LATER_BUILDLINK3_MK

BUILDLINK_TREE+=	-R-later
