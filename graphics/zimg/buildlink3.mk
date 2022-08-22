# $NetBSD: buildlink3.mk,v 1.1 2022/08/22 13:50:37 ast Exp $

BUILDLINK_TREE+=	zimg

.if !defined(ZIMG_BUILDLINK3_MK)
ZIMG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zimg+=	zimg>=3.0.4
BUILDLINK_PKGSRCDIR.zimg?=	../../graphics/zimg
.endif	# ZIMG_BUILDLINK3_MK

BUILDLINK_TREE+=	-zimg
