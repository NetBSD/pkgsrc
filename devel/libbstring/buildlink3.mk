# $NetBSD: buildlink3.mk,v 1.1 2025/08/12 18:13:55 hauke Exp $

BUILDLINK_TREE+=	libbstring

.if !defined(LIBBSTRING_BUILDLINK3_MK)
LIBBSTRING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libbstring+=	libbstring>=1.0.1
BUILDLINK_PKGSRCDIR.libbstring?=	../../devel/libbstring
.endif # LIBBSTRING_BUILDLINK3_MK

BUILDLINK_TREE+=	-libbstring
