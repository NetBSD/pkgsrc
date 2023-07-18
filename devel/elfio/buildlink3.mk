# $NetBSD: buildlink3.mk,v 1.3 2023/07/18 14:11:15 nia Exp $

BUILDLINK_TREE+=	elfio

.if !defined(ELFIO_BUILDLINK3_MK)
ELFIO_BUILDLINK3_MK:=

USE_CXX_FEATURES+=		unique_ptr

BUILDLINK_DEPMETHOD.elfio?=	build
BUILDLINK_API_DEPENDS.elfio+=	elfio>=3.9
BUILDLINK_PKGSRCDIR.elfio?=	../../devel/elfio
.endif

BUILDLINK_TREE+=	-elfio
