# $NetBSD: buildlink3.mk,v 1.3 2013/02/06 23:21:34 jperkin Exp $

BUILDLINK_TREE+=	ykclient

.if !defined(YKCLIENT_BUILDLINK3_MK)
YKCLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ykclient+=	ykclient>=2.7
BUILDLINK_ABI_DEPENDS.ykclient?=	ykclient>=2.9nb2
BUILDLINK_PKGSRCDIR.ykclient?=	../../security/ykclient

.include "../../www/curl/buildlink3.mk"
.endif	# YKCLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ykclient
