# $NetBSD: buildlink3.mk,v 1.7 2024/04/26 11:48:09 micha Exp $

BUILDLINK_TREE+=	avr-binutils

.if !defined(AVR_BINUTILS_BUILDLINK3_MK)
AVR_BINUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.avr-binutils+=		avr-binutils>=2.37
BUILDLINK_ABI_DEPENDS.avr-binutils?=		avr-binutils>=2.42
BUILDLINK_PKGSRCDIR.avr-binutils?=		../../cross/avr-binutils

.endif # AVR_BINUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-avr-binutils
