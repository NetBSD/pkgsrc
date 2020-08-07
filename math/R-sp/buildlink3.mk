# $NetBSD: buildlink3.mk,v 1.1 2020/08/07 00:08:36 brook Exp $

BUILDLINK_TREE+=	R-sp

.if !defined(R_SP_BUILDLINK3_MK)
R_SP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.R-sp+=	R-sp>=1.4.2
BUILDLINK_PKGSRCDIR.R-sp?=	../../math/R-sp
.endif	# R_SP_BUILDLINK3_MK

BUILDLINK_TREE+=	-R-sp
