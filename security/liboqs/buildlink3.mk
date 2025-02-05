# $NetBSD: buildlink3.mk,v 1.2 2025/02/05 02:46:30 jschauma Exp $

BUILDLINK_TREE+=	liboqs

.if !defined(LIBOQS_BUILDLINK3_MK)
LIBOQS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liboqs+=	liboqs>=0.12.0
BUILDLINK_PKGSRCDIR.liboqs?=	../../security/liboqs

.endif	# LIBOQS_BUILDLINK3_MK

BUILDLINK_TREE+=	-liboqs
