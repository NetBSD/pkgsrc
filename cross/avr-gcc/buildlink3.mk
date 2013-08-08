# $NetBSD: buildlink3.mk,v 1.1 2013/08/08 03:14:57 mef Exp $

BUILDLINK_TREE+=	avr-gcc

.if !defined(AVR_GCC_BUILDLINK3_MK)
AVR_GCC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.avr-gcc+=		avr-gcc>=4.5.3
BUILDLINK_PKGSRCDIR.avr-gcc?=		../../cross/avr-gcc
BUILDLINK_FNAME_TRANSFORM.avr-gcc+=	-e "s,${AVR_TARGET}/lib,lib/,g"

.endif # AVR_GCC_BUILDLINK3_MK

BUILDLINK_TREE+=	-avr-gcc
