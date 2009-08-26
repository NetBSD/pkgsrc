# $NetBSD: buildlink3.mk,v 1.4 2009/08/26 19:56:40 sno Exp $

BUILDLINK_TREE+=	libVNCServer

.if !defined(LIBVNCSERVER_BUILDLINK3_MK)
LIBVNCSERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libVNCServer+=	libVNCServer>=0.9.1
BUILDLINK_ABI_DEPENDS.libVNCServer?=	libVNCServer>=0.9.7nb1
BUILDLINK_PKGSRCDIR.libVNCServer?=	../../net/libvncserver

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.endif # LIBVNCSERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libVNCServer
