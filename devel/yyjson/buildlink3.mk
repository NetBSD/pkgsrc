# $NetBSD: buildlink3.mk,v 1.2 2025/05/11 07:31:56 vins Exp $

BUILDLINK_TREE+=	yyjson

.if !defined(YYJSON_BUILDLINK3_MK)
YYJSON_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.yyjson?=	build

BUILDLINK_API_DEPENDS.yyjson+=	yyjson>=0.10.0
BUILDLINK_API_DEPENDS.yyjson+=	yyjson>=0.11.0
BUILDLINK_PKGSRCDIR.yyjson?=	../../devel/yyjson

BUILDLINK_LIBNAME.yyjson=	yyjson
BUILDLINK_LDADD.yyjson+=	${BUILDLINK_LIBNAME.yyjson:S/^/-l/:S/^-l$//}

.endif	# YYJSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-yyjson
