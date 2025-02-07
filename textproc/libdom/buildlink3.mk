# $NetBSD: buildlink3.mk,v 1.1 2025/02/07 16:03:47 pho Exp $

BUILDLINK_TREE+=	libdom

.if !defined(LIBDOM_BUILDLINK3_MK)
LIBDOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdom+=	libdom>=0.4.2
BUILDLINK_PKGSRCDIR.libdom?=	../../textproc/libdom

.include "../../devel/libwapcaplet/buildlink3.mk"
.include "../../textproc/libparserutils/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/libhubbub/buildlink3.mk"
.endif	# LIBDOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdom
