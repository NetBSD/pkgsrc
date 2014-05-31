# $NetBSD: buildlink3.mk,v 1.6 2014/05/31 23:44:19 wiz Exp $

BUILDLINK_TREE+=	giflib

.if !defined(GIFLIB_BUILDLINK3_MK)
GIFLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.giflib+=	giflib>=5.1.0
BUILDLINK_PKGSRCDIR.giflib?=	../../graphics/giflib
.endif	# GIFLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-giflib
