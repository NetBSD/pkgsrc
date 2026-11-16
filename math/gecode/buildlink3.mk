# $NetBSD: buildlink3.mk,v 1.1 2026/11/16 22:58:51 alnsn Exp $

BUILDLINK_TREE+=	gecode

.if !defined(GECODE_BUILDLINK3_MK)
GECODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gecode+=	gecode>=6.6.0
BUILDLINK_ABI_DEPENDS.gecode+=	gecode>=6.6.0
BUILDLINK_PKGSRCDIR.gecode?=	../../math/gecode

.endif	# GECODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-gecode
