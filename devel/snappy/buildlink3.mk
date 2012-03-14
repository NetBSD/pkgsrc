# $NetBSD: buildlink3.mk,v 1.1 2012/03/14 18:16:15 abs Exp $

BUILDLINK_TREE+=	snappy

.if !defined(SNAPPY_BUILDLINK3_MK)
SNAPPY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.snappy+=	snappy>=1.0.5
BUILDLINK_ABI_DEPENDS.snappy+=	snappy>=1.0.5
BUILDLINK_PKGSRCDIR.snappy?=	../../devel/snappy
.endif # SNAPPY_BUILDLINK3_MK

BUILDLINK_TREE+=	-snappy
