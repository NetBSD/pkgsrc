# $NetBSD: buildlink3.mk,v 1.3 2025/09/12 21:07:54 jschauma Exp $

BUILDLINK_TREE+=	liboqs

.if !defined(LIBOQS_BUILDLINK3_MK)
LIBOQS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liboqs+=	liboqs>=0.14.0
BUILDLINK_PKGSRCDIR.liboqs?=	../../security/liboqs

.endif	# LIBOQS_BUILDLINK3_MK

BUILDLINK_TREE+=	-liboqs
