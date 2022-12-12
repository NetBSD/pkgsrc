# $NetBSD: buildlink3.mk,v 1.2 2022/12/12 14:44:34 nros Exp $

BUILDLINK_TREE+=	elfio

.if !defined(ELFIO_BUILDLINK3_MK)
ELFIO_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.elfio?=	build
BUILDLINK_API_DEPENDS.elfio+=	elfio>=3.9
BUILDLINK_PKGSRCDIR.elfio?=	../../devel/elfio
.endif

BUILDLINK_TREE+=	-elfio
