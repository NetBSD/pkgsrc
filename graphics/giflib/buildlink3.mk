# $NetBSD: buildlink3.mk,v 1.9 2020/06/05 12:48:59 jperkin Exp $

BUILDLINK_TREE+=	giflib

.if !defined(GIFLIB_BUILDLINK3_MK)
GIFLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.giflib+=	giflib>=5.2.1nb3
BUILDLINK_ABI_DEPENDS.giflib?=	giflib>=5.2.1nb4
BUILDLINK_PKGSRCDIR.giflib?=	../../graphics/giflib
.endif	# GIFLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-giflib
