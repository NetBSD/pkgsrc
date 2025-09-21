# $NetBSD: buildlink3.mk,v 1.5 2025/09/21 18:15:04 wiz Exp $

BUILDLINK_TREE+=	fmtlib

.if !defined(FMTLIB_BUILDLINK3_MK)
FMTLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fmtlib+=	fmtlib>=5.2.1
BUILDLINK_ABI_DEPENDS.fmtlib+=	fmtlib>=12.0.0
BUILDLINK_PKGSRCDIR.fmtlib?=	../../textproc/fmtlib
.endif	# FMTLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-fmtlib
