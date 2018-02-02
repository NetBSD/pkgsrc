# $NetBSD: buildlink3.mk,v 1.1 2018/02/02 13:17:57 jperkin Exp $

BUILDLINK_TREE+=	libdmtx

.if !defined(LIBDMTX_BUILDLINK3_MK)
LIBDMTX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdmtx+=	libdmtx>=0.7.4
BUILDLINK_PKGSRCDIR.libdmtx?=	../../graphics/libdmtx
.endif	# LIBDMTX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdmtx
