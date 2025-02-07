# $NetBSD: buildlink3.mk,v 1.1 2025/02/07 16:01:08 pho Exp $

BUILDLINK_TREE+=	libparserutils

.if !defined(LIBPARSERUTILS_BUILDLINK3_MK)
LIBPARSERUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libparserutils+=	libparserutils>=0.2.5
BUILDLINK_PKGSRCDIR.libparserutils?=	../../textproc/libparserutils

.include "../../converters/libiconv/buildlink3.mk"
.endif	# LIBPARSERUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libparserutils
