# $NetBSD: buildlink3.mk,v 1.1 2018/04/30 04:53:25 ryoon Exp $

BUILDLINK_TREE+=	libmypaint

.if !defined(LIBMYPAINT_BUILDLINK3_MK)
LIBMYPAINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmypaint+=	libmypaint>=1.3.0
BUILDLINK_PKGSRCDIR.libmypaint?=	../../graphics/libmypaint

.include "../../textproc/json-c/buildlink3.mk"
.endif	# LIBMYPAINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmypaint
