# $NetBSD: buildlink3.mk,v 1.1 2017/07/17 03:25:32 schmonz Exp $

BUILDLINK_TREE+=	libidn2

.if !defined(LIBIDN2_BUILDLINK3_MK)
LIBIDN2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libidn2+=	libidn2>=2.0.0
BUILDLINK_PKGSRCDIR.libidn2?=	../../devel/libidn2
.endif	# LIBIDN2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libidn2
