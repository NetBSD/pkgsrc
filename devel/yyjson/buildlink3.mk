# $NetBSD: buildlink3.mk,v 1.4 2025/06/07 15:34:05 vins Exp $

BUILDLINK_TREE+=	yyjson

.if !defined(YYJSON_BUILDLINK3_MK)
YYJSON_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.yyjson?=	build

BUILDLINK_API_DEPENDS.yyjson+=	yyjson>=0.10.0
BUILDLINK_ABI_DEPENDS.yyjson+=	yyjson>=0.11.1
BUILDLINK_PKGSRCDIR.yyjson?=	../../devel/yyjson

BUILDLINK_LIBNAME.yyjson=	yyjson
BUILDLINK_LDADD.yyjson+=	${BUILDLINK_LIBNAME.yyjson:S/^/-l/:S/^-l$//}

.endif	# YYJSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-yyjson
