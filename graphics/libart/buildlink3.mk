# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:41 joerg Exp $

BUILDLINK_TREE+=	libart

.if !defined(LIBART_BUILDLINK3_MK)
LIBART_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libart+=	libart>=2.3.10nb1
BUILDLINK_ABI_DEPENDS.libart+=	libart>=2.3.16nb1
BUILDLINK_PKGSRCDIR.libart?=	../../graphics/libart
.endif # LIBART_BUILDLINK3_MK

BUILDLINK_TREE+=	-libart
