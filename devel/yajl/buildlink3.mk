# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/03/18 16:56:32 abs Exp $

BUILDLINK_TREE+=	yajl

.if !defined(YAJL_BUILDLINK3_MK)
YAJL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.yajl+=	yajl>=1.0.9
BUILDLINK_PKGSRCDIR.yajl?=	../../devel/yajl
.endif	# YAJL_BUILDLINK3_MK

BUILDLINK_TREE+=	-yajl
