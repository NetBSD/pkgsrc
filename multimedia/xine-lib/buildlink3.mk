# $NetBSD: buildlink3.mk,v 1.32 2015/11/18 14:19:47 ryoon Exp $

BUILDLINK_TREE+=	xine-lib

.if !defined(XINE_LIB_BUILDLINK3_MK)
XINE_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xine-lib+=	xine-lib>=1rc3c
BUILDLINK_ABI_DEPENDS.xine-lib+=	xine-lib>=1.2.6nb3
BUILDLINK_PKGSRCDIR.xine-lib?=	../../multimedia/xine-lib

.include "../../multimedia/ffmpeg2/buildlink3.mk"
.endif # XINE_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-xine-lib
