# $NetBSD: buildlink3.mk,v 1.2 2023/05/16 21:20:49 wiz Exp $

BUILDLINK_TREE+=	fmtlib

.if !defined(FMTLIB_BUILDLINK3_MK)
FMTLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fmtlib+=	fmtlib>=5.2.1
BUILDLINK_ABI_DEPENDS.fmtlib?=	fmtlib>=10.0.0
BUILDLINK_PKGSRCDIR.fmtlib?=	../../textproc/fmtlib
.endif	# FMTLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-fmtlib
