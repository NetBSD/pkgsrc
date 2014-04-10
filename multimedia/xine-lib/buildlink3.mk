# $NetBSD: buildlink3.mk,v 1.27 2014/04/10 05:39:14 obache Exp $

BUILDLINK_TREE+=	xine-lib

.if !defined(XINE_LIB_BUILDLINK3_MK)
XINE_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xine-lib+=	xine-lib>=1rc3c
BUILDLINK_ABI_DEPENDS.xine-lib+=xine-lib>=1.0.3a
BUILDLINK_ABI_DEPENDS.xine-lib+=	xine-lib>=1.2.4nb3
BUILDLINK_PKGSRCDIR.xine-lib?=	../../multimedia/xine-lib

.include "../../multimedia/ffmpeg/buildlink3.mk"
.endif # XINE_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-xine-lib
