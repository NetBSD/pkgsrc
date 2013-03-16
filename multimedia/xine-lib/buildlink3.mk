# $NetBSD: buildlink3.mk,v 1.26 2013/03/16 06:20:45 obache Exp $

BUILDLINK_TREE+=	xine-lib

.if !defined(XINE_LIB_BUILDLINK3_MK)
XINE_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xine-lib+=	xine-lib>=1rc3c
BUILDLINK_ABI_DEPENDS.xine-lib+=xine-lib>=1.0.3a
BUILDLINK_ABI_DEPENDS.xine-lib+=	xine-lib>=1.2.2nb8
BUILDLINK_PKGSRCDIR.xine-lib?=	../../multimedia/xine-lib

.include "../../multimedia/ffmpeg/buildlink3.mk"
.endif # XINE_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-xine-lib
