# $NetBSD: buildlink3.mk,v 1.10 2014/03/18 14:41:27 gdt Exp $

BUILDLINK_TREE+=	fribidi

.if !defined(FRIBIDI_BUILDLINK3_MK)
FRIBIDI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fribidi+=	fribidi>=0.19.1
BUILDLINK_ABI_DEPENDS.fribidi+=	fribidi>=0.10.4nb1
BUILDLINK_PKGSRCDIR.fribidi?=	../../converters/fribidi
.endif # FRIBIDI_BUILDLINK3_MK

BUILDLINK_TREE+=	-fribidi
