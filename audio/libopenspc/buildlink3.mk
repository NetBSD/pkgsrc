# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:23:56 joerg Exp $

BUILDLINK_TREE+=	libopenspc

.if !defined(LIBOPENSPC_BUILDLINK3_MK)
LIBOPENSPC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libopenspc+=	libopenspc>=0.3.99.20050926
BUILDLINK_PKGSRCDIR.libopenspc?=	../../audio/libopenspc
.endif # LIBOPENSPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libopenspc
