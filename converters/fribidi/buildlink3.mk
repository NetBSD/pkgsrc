# $NetBSD: buildlink3.mk,v 1.9 2014/03/18 01:02:28 gdt Exp $

BUILDLINK_TREE+=	fribidi

.if !defined(FRIBIDI_BUILDLINK3_MK)
FRIBIDI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fribidi+=	fribidi>=0.19.1
BUILDLINK_PKGSRCDIR.fribidi?=	../../converters/fribidi
.endif # FRIBIDI_BUILDLINK3_MK

BUILDLINK_TREE+=	-fribidi
