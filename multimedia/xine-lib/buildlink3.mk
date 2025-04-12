# $NetBSD: buildlink3.mk,v 1.50 2025/04/12 06:54:25 wiz Exp $

BUILDLINK_TREE+=	xine-lib

.if !defined(XINE_LIB_BUILDLINK3_MK)
XINE_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xine-lib+=	xine-lib>=1rc3c
BUILDLINK_ABI_DEPENDS.xine-lib+=	xine-lib>=1.2.12nb27
BUILDLINK_PKGSRCDIR.xine-lib?=		../../multimedia/xine-lib

.include "../../multimedia/ffmpeg4/buildlink3.mk"
.endif # XINE_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-xine-lib
