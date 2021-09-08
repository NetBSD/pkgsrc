# $NetBSD: buildlink3.mk,v 1.3 2021/09/08 12:07:06 micha Exp $

BUILDLINK_TREE+=	avr-gcc

.if !defined(AVR_GCC_BUILDLINK3_MK)
AVR_GCC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.avr-gcc+=	avr-gcc>=10.3.0
BUILDLINK_PKGSRCDIR.avr-gcc?=	../../cross/avr-gcc
.endif	# AVR_GCC_BUILDLINK3_MK

BUILDLINK_TREE+=	-avr-gcc
