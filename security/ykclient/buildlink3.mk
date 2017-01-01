# $NetBSD: buildlink3.mk,v 1.7 2017/01/01 16:06:00 adam Exp $

BUILDLINK_TREE+=	ykclient

.if !defined(YKCLIENT_BUILDLINK3_MK)
YKCLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ykclient+=	ykclient>=2.7
BUILDLINK_ABI_DEPENDS.ykclient?=	ykclient>=2.13nb4
BUILDLINK_PKGSRCDIR.ykclient?=	../../security/ykclient

.include "../../www/curl/buildlink3.mk"
.endif	# YKCLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ykclient
