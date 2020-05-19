# $NetBSD: buildlink3.mk,v 1.3 2020/05/19 12:09:08 nia Exp $

BUILDLINK_TREE+=	libmypaint

.if !defined(LIBMYPAINT_BUILDLINK3_MK)
LIBMYPAINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmypaint+=	libmypaint>=1.4.0
BUILDLINK_ABI_DEPENDS.libmypaint?=	libmypaint>=1.5.1nb1
BUILDLINK_PKGSRCDIR.libmypaint?=	../../graphics/libmypaint

.include "../../textproc/json-c/buildlink3.mk"
.endif	# LIBMYPAINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmypaint
