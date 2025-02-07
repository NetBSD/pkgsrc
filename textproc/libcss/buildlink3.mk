# $NetBSD: buildlink3.mk,v 1.1 2025/02/07 16:02:10 pho Exp $

BUILDLINK_TREE+=	libcss

.if !defined(LIBCSS_BUILDLINK3_MK)
LIBCSS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcss+=	libcss>=0.9.2
BUILDLINK_PKGSRCDIR.libcss?=	../../textproc/libcss

.include "../../devel/libwapcaplet/buildlink3.mk"
.include "../../textproc/libparserutils/buildlink3.mk"
.endif	# LIBCSS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcss
