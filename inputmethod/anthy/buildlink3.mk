# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:46 joerg Exp $

BUILDLINK_TREE+=	anthy

.if !defined(ANTHY_BUILDLINK3_MK)
ANTHY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.anthy+=	anthy>=6300
BUILDLINK_ABI_DEPENDS.anthy?=	anthy>=7900
BUILDLINK_PKGSRCDIR.anthy?=	../../inputmethod/anthy
.endif # ANTHY_BUILDLINK3_MK

BUILDLINK_TREE+=	-anthy
