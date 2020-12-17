# $NetBSD: buildlink3.mk,v 1.1 2020/12/17 22:12:06 mef Exp $

BUILDLINK_TREE+=	erfa

.if !defined(ERFA_BUILDLINK3_MK)
ERFA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.erfa+=	erfa>=1.7.1
BUILDLINK_PKGSRCDIR.erfa?=	../../math/erfa
.endif	# ERFA_BUILDLINK3_MK

BUILDLINK_TREE+=	-erfa
