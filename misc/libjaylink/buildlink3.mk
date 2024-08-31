# $NetBSD: buildlink3.mk,v 1.1 2024/08/31 19:41:34 jakllsch Exp $

BUILDLINK_TREE+=	libjaylink

.if !defined(LIBJAYLINK_BUILDLINK3_MK)
LIBJAYLINK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libjaylink+=	libjaylink>=0.3.1
BUILDLINK_PKGSRCDIR.libjaylink?=	../../misc/libjaylink
.endif	# LIBJAYLINK_BUILDLINK3_MK

BUILDLINK_TREE+=	-libjaylink
