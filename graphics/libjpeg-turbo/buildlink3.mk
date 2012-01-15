# $NetBSD: buildlink3.mk,v 1.2 2012/01/15 10:11:53 obache Exp $

BUILDLINK_TREE+=	libjpeg-turbo

.if !defined(LIBJPEG_TURBO_BUILDLINK3_MK)
LIBJPEG_TURBO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libjpeg-turbo+=	libjpeg-turbo>=1.1.0
BUILDLINK_PKGSRCDIR.libjpeg-turbo?=	../../graphics/libjpeg-turbo
.endif	# LIBJPEG_TURBO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libjpeg-turbo
