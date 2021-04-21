# $NetBSD: buildlink3.mk,v 1.23 2021/04/21 13:24:16 adam Exp $

BUILDLINK_TREE+=	ykclient

.if !defined(YKCLIENT_BUILDLINK3_MK)
YKCLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ykclient+=	ykclient>=2.7
BUILDLINK_ABI_DEPENDS.ykclient?=	ykclient>=2.15nb6
BUILDLINK_PKGSRCDIR.ykclient?=		../../security/ykclient

.include "../../www/curl/buildlink3.mk"
.endif	# YKCLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ykclient
