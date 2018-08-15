# $NetBSD: buildlink3.mk,v 1.1 2018/08/15 14:02:46 ryoon Exp $

BUILDLINK_TREE+=	libnumbertext

.if !defined(LIBNUMBERTEXT_BUILDLINK3_MK)
LIBNUMBERTEXT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnumbertext+=	libnumbertext>=1.0.3
BUILDLINK_PKGSRCDIR.libnumbertext?=	../../math/libnumbertext
.endif	# LIBNUMBERTEXT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnumbertext
