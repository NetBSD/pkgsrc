# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:24:23 joerg Exp $

BUILDLINK_TREE+=	libtar

.if !defined(LIBTAR_BUILDLINK3_MK)
LIBTAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtar+=	libtar>=1.2.11
BUILDLINK_PKGSRCDIR.libtar?=	../../devel/libtar

.include "../../devel/zlib/buildlink3.mk"
.endif # LIBTAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtar
