# $NetBSD: buildlink3.mk,v 1.2 2023/10/23 14:04:18 micha Exp $

BUILDLINK_TREE+=	utf8proc

.if !defined(UTF8PROC_BUILDLINK3_MK)
UTF8PROC_BUILDLINK3_MK:=

USE_CC_FEATURES+=	c99

BUILDLINK_API_DEPENDS.utf8proc+=	utf8proc>=2.1.1
BUILDLINK_ABI_DEPENDS.utf8proc+=	utf8proc>=2.9.0
BUILDLINK_PKGSRCDIR.utf8proc?=		../../converters/utf8proc
.endif	# UTF8PROC_BUILDLINK3_MK

BUILDLINK_TREE+=	-utf8proc
