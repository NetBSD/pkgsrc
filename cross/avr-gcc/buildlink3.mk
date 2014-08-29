# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 04:26:46 mef Exp $

BUILDLINK_TREE+=	avr-gcc

.if !defined(AVR_GCC_BUILDLINK3_MK)
AVR_GCC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.avr-gcc+=		avr-gcc>=4.8.3
BUILDLINK_PKGSRCDIR.avr-gcc?=		../../cross/avr-gcc
# Folling line was harmful, .buildlink/lib/ -> buildlinklib/
# It did not have first ending slash, probably was OK.
#BUILDLINK_FNAME_TRANSFORM.avr-gcc+=	-e "s,${AVR_TARGET}/lib/,lib/,g"

.endif # AVR_GCC_BUILDLINK3_MK

BUILDLINK_TREE+=	-avr-gcc
