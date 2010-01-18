# $NetBSD: buildlink3.mk,v 1.5 2010/01/18 09:59:20 wiz Exp $

BUILDLINK_TREE+=	libVNCServer

.if !defined(LIBVNCSERVER_BUILDLINK3_MK)
LIBVNCSERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libVNCServer+=	libVNCServer>=0.9.1
BUILDLINK_ABI_DEPENDS.libVNCServer?=	libVNCServer>=0.9.7nb2
BUILDLINK_PKGSRCDIR.libVNCServer?=	../../net/libvncserver

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.endif # LIBVNCSERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libVNCServer
