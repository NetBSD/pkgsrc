# $NetBSD: buildlink3.mk,v 1.13 2009/03/20 19:24:32 joerg Exp $

BUILDLINK_TREE+=	pico

.if !defined(PICO_BUILDLINK3_MK)
PICO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pico+=	pico>=4.10
BUILDLINK_PKGSRCDIR.pico?=	../../editors/pico
.endif # PICO_BUILDLINK3_MK

BUILDLINK_TREE+=	-pico
