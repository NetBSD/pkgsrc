# $NetBSD: buildlink3.mk,v 1.1 2018/12/02 17:12:18 adam Exp $

BUILDLINK_TREE+=	fmtlib

.if !defined(FMTLIB_BUILDLINK3_MK)
FMTLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fmtlib+=	fmtlib>=5.2.1
BUILDLINK_PKGSRCDIR.fmtlib?=	../../textproc/fmtlib
.endif	# FMTLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-fmtlib
