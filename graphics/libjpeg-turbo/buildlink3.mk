# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/12/12 11:48:56 dsainty Exp $

BUILDLINK_TREE+=	libjpeg-turbo

.if !defined(LIBJPEG_TURBO_BUILDLINK3_MK)
LIBJPEG_TURBO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libjpeg-turbo+=	libjpeg-turbo>=1.0.1
BUILDLINK_PKGSRCDIR.libjpeg-turbo?=	../../graphics/libjpeg-turbo
.endif	# LIBJPEG_TURBO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libjpeg-turbo
