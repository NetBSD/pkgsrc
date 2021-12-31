# $NetBSD: buildlink3.mk,v 1.1 2021/12/31 17:24:31 plunky Exp $

BUILDLINK_TREE+=	elfio

.if !defined(ELFIO_BUILDLINK3_MK)
ELFIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.elfio+=	elfio>=3.9
BUILDLINK_PKGSRCDIR.elfio?=	../../devel/elfio
.endif

BUILDLINK_TREE+=	-elfio
