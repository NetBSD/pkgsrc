# $NetBSD: buildlink3.mk,v 1.6 2025/09/28 16:22:15 bsiegert Exp $

BUILDLINK_TREE+=		libtirpc

.if !defined(LIBTIRPC_BUILDLINK3_MK)
LIBTIRPC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtirpc+=	libtirpc>=1.3.3
BUILDLINK_ABI_DEPENDS.libtirpc+=	libtirpc>=1.3.7
BUILDLINK_PKGSRCDIR.libtirpc?=		../../devel/libtirpc

BUILDLINK_INCDIRS.libtirpc?=	include/tirpc
BUILDLINK_LIBNAME.libtirpc=	tirpc
BUILDLINK_LIBS.libtirpc=	${BUILDLINK_LIBNAME.libtirpc:S/^/-l/:S/^-l$//}

.endif	# LIBTIRPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtirpc
