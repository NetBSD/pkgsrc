# $NetBSD: buildlink3.mk,v 1.4 2013/07/05 13:23:20 ryoon Exp $

.if !defined(MK_GIFLIB_BUILDLINK3_MK)
PKG_FAIL_REASON= "please use giflib.buildlink3.mk"
.endif

BUILDLINK_TREE+=	giflib

.if !defined(GIFLIB_BUILDLINK3_MK)
GIFLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.giflib+=	giflib>=5.0.4
BUILDLINK_PKGSRCDIR.giflib?=	../../graphics/giflib
.endif	# GIFLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-giflib
