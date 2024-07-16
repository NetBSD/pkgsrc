# $NetBSD: buildlink3.mk,v 1.4 2024/07/16 10:02:05 prlw1 Exp $

BUILDLINK_TREE+=	fmtlib

.if !defined(FMTLIB_BUILDLINK3_MK)
FMTLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fmtlib+=	fmtlib>=5.2.1
BUILDLINK_ABI_DEPENDS.fmtlib+=	fmtlib>=11.0.1
BUILDLINK_PKGSRCDIR.fmtlib?=	../../textproc/fmtlib
.endif	# FMTLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-fmtlib
