# $NetBSD: buildlink3.mk,v 1.4 2014/02/12 23:18:37 tron Exp $

BUILDLINK_TREE+=	ykclient

.if !defined(YKCLIENT_BUILDLINK3_MK)
YKCLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ykclient+=	ykclient>=2.7
BUILDLINK_ABI_DEPENDS.ykclient?=	ykclient>=2.11nb1
BUILDLINK_PKGSRCDIR.ykclient?=	../../security/ykclient

.include "../../www/curl/buildlink3.mk"
.endif	# YKCLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ykclient
