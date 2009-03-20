# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:24:03 joerg Exp $

BUILDLINK_TREE+=	fribidi

.if !defined(FRIBIDI_BUILDLINK3_MK)
FRIBIDI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fribidi+=	fribidi>=0.10.4
BUILDLINK_ABI_DEPENDS.fribidi+=	fribidi>=0.10.4nb1
BUILDLINK_PKGSRCDIR.fribidi?=	../../converters/fribidi
.endif # FRIBIDI_BUILDLINK3_MK

BUILDLINK_TREE+=	-fribidi
