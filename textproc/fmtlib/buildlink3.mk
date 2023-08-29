# $NetBSD: buildlink3.mk,v 1.3 2023/08/29 07:08:09 adam Exp $

BUILDLINK_TREE+=	fmtlib

.if !defined(FMTLIB_BUILDLINK3_MK)
FMTLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fmtlib+=	fmtlib>=5.2.1
BUILDLINK_ABI_DEPENDS.fmtlib+=	fmtlib>=10.0.0
BUILDLINK_PKGSRCDIR.fmtlib?=	../../textproc/fmtlib
.endif	# FMTLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-fmtlib
