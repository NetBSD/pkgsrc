# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:46 joerg Exp $

BUILDLINK_TREE+=	Canna-lib

.if !defined(CANNA_LIB_BUILDLINK3_MK)
CANNA_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Canna-lib+=	Canna-lib>=3.6pl4
BUILDLINK_PKGSRCDIR.Canna-lib?=	../../inputmethod/canna-lib
.endif # CANNA_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-Canna-lib
