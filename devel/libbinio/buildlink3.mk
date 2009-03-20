# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:24:16 joerg Exp $

BUILDLINK_TREE+=	libbinio

.if !defined(LIBBINIO_BUILDLINK3_MK)
LIBBINIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libbinio+=	libbinio>=1.4
BUILDLINK_PKGSRCDIR.libbinio?=		../../devel/libbinio
.endif # LIBBINIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libbinio
