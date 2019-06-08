# $NetBSD: buildlink3.mk,v 1.4 2019/06/08 10:53:26 rillig Exp $

BUILDLINK_TREE+=	avr-binutils

.if !defined(AVR_BINUTILS_BUILDLINK3_MK)
AVR_BINUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.avr-binutils+=		avr-binutils>=2.23
BUILDLINK_PKGSRCDIR.avr-binutils?=		../../cross/avr-binutils
#BUILDLINK_FNAME_TRANSFORM.avr-binutils+=	-e "s,${AVR_TARGET}/lib,lib/,g"

.endif # AVR_BINUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-avr-binutils
