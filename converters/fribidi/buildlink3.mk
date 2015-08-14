# $NetBSD: buildlink3.mk,v 1.11 2015/08/14 20:08:43 wiz Exp $

BUILDLINK_TREE+=	fribidi

.if !defined(FRIBIDI_BUILDLINK3_MK)
FRIBIDI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fribidi+=	fribidi>=0.19.1
BUILDLINK_PKGSRCDIR.fribidi?=	../../converters/fribidi
.endif # FRIBIDI_BUILDLINK3_MK

BUILDLINK_TREE+=	-fribidi
