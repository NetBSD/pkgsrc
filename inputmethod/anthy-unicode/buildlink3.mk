# $NetBSD: buildlink3.mk,v 1.1 2026/08/28 11:30:25 wiz Exp $

BUILDLINK_TREE+=	anthy-unicode

.if !defined(ANTHY_UNICODE_BUILDLINK3_MK)
ANTHY_UNICODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.anthy-unicode+=	anthy-unicode>=1.0.0.20260213
BUILDLINK_PKGSRCDIR.anthy-unicode?=	../../inputmethod/anthy-unicode
.endif # ANTHY_UNICODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-anthy-unicode
