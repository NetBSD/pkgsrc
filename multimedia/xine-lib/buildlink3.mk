# $NetBSD: buildlink3.mk,v 1.47 2023/01/29 21:14:53 ryoon Exp $

BUILDLINK_TREE+=	xine-lib

.if !defined(XINE_LIB_BUILDLINK3_MK)
XINE_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xine-lib+=	xine-lib>=1rc3c
BUILDLINK_ABI_DEPENDS.xine-lib+=	xine-lib>=1.2.12nb12
BUILDLINK_PKGSRCDIR.xine-lib?=		../../multimedia/xine-lib

.include "../../multimedia/ffmpeg4/buildlink3.mk"
.endif # XINE_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-xine-lib
