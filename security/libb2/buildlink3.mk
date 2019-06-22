# $NetBSD: buildlink3.mk,v 1.1 2019/06/22 18:54:04 bsiegert Exp $

BUILDLINK_TREE+=	libb2

.if !defined(LIBB2_BUILDLINK3_MK)
LIBB2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libb2+=	libb2>=0.98.1
BUILDLINK_PKGSRCDIR.libb2?=	../../security/libb2
.endif	# LIBB2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libb2
