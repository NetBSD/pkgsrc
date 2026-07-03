# $NetBSD: buildlink3.mk,v 1.10 2026/07/03 20:00:01 tsutsui Exp $

BUILDLINK_TREE+=	Canna-lib

.if !defined(CANNA_LIB_BUILDLINK3_MK)
CANNA_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Canna-lib+=	Canna-lib>=3.8
BUILDLINK_PKGSRCDIR.Canna-lib?=		../../inputmethod/canna-lib
.endif # CANNA_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-Canna-lib
