# $NetBSD: buildlink3.mk,v 1.3 2024/02/11 17:46:17 vins Exp $

BUILDLINK_TREE+=	libmd

.if !defined(LIBMD_BUILDLINK3_MK)
LIBMD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmd+=	libmd>=1.1.0
BUILDLINK_ABI_DEPENDS.libmd+=	libmd>=1.1.0
BUILDLINK_PKGSRCDIR.libmd?=	../../devel/libmd

BUILDLINK_LIBNAME.libmd=	md
BUILDLINK_LDADD.libmd=		${BUILDLINK_LIBNAME.libmd:S/^/-l/:S/^-l$//}

.endif	# LIBMD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmd
