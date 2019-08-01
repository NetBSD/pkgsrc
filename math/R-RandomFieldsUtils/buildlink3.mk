# $NetBSD: buildlink3.mk,v 1.1 2019/08/01 14:26:45 brook Exp $

BUILDLINK_TREE+=	R-RandomFieldsUtils

.if !defined(R_RANDOMFIELDSUTILS_BUILDLINK3_MK)
R_RANDOMFIELDSUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.R-RandomFieldsUtils+=	R-RandomFieldsUtils>=0.5.3
BUILDLINK_PKGSRCDIR.R-RandomFieldsUtils?=	../../math/R-RandomFieldsUtils
.endif	# R_RANDOMFIELDSUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-R-RandomFieldsUtils
