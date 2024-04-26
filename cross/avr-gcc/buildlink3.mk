# $NetBSD: buildlink3.mk,v 1.4 2024/04/26 13:05:01 micha Exp $

BUILDLINK_TREE+=	avr-gcc

.if !defined(AVR_GCC_BUILDLINK3_MK)
AVR_GCC_BUILDLINK3_MK:=

USE_CXX_FEATURES+=	c++11

BUILDLINK_API_DEPENDS.avr-gcc+=	avr-gcc>=13.2.0
BUILDLINK_PKGSRCDIR.avr-gcc?=	../../cross/avr-gcc
.endif	# AVR_GCC_BUILDLINK3_MK

BUILDLINK_TREE+=	-avr-gcc
