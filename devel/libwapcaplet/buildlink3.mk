# $NetBSD: buildlink3.mk,v 1.1 2025/02/07 15:59:47 pho Exp $

BUILDLINK_TREE+=	libwapcaplet

.if !defined(LIBWAPCAPLET_BUILDLINK3_MK)
LIBWAPCAPLET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwapcaplet+=	libwapcaplet>=0.4.3
BUILDLINK_PKGSRCDIR.libwapcaplet?=	../../devel/libwapcaplet
.endif	# LIBWAPCAPLET_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwapcaplet
