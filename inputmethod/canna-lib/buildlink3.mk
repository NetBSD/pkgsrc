# $NetBSD: buildlink3.mk,v 1.8 2015/10/18 03:58:31 tsutsui Exp $

BUILDLINK_TREE+=	Canna-lib

.if !defined(CANNA_LIB_BUILDLINK3_MK)
CANNA_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Canna-lib+=	Canna-lib>=3.7pl3
BUILDLINK_PKGSRCDIR.Canna-lib?=	../../inputmethod/canna-lib
.endif # CANNA_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-Canna-lib
