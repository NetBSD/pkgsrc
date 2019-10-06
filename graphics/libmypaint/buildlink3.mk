# $NetBSD: buildlink3.mk,v 1.2 2019/10/06 12:23:03 nia Exp $

BUILDLINK_TREE+=	libmypaint

.if !defined(LIBMYPAINT_BUILDLINK3_MK)
LIBMYPAINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmypaint+=	libmypaint>=1.4.0
BUILDLINK_PKGSRCDIR.libmypaint?=	../../graphics/libmypaint

.include "../../textproc/json-c/buildlink3.mk"
.endif	# LIBMYPAINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmypaint
