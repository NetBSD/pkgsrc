# $NetBSD: buildlink3.mk,v 1.5 2014/05/16 10:23:28 obache Exp $

.if !defined(MK_GIFLIB_BUILDLINK3_MK)
PKG_FAIL_REASON= "please use giflib.buildlink3.mk"
.endif

BUILDLINK_TREE+=	giflib

.if !defined(GIFLIB_BUILDLINK3_MK)
GIFLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.giflib+=	giflib>=5.1.0
BUILDLINK_PKGSRCDIR.giflib?=	../../graphics/giflib
.endif	# GIFLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-giflib
