# $NetBSD: buildlink3.mk,v 1.1 2024/09/13 18:02:45 jschauma Exp $

BUILDLINK_TREE+=	liboqs

.if !defined(LIBOQS_BUILDLINK3_MK)
LIBOQS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liboqs+=	liboqs>=0.10.1
BUILDLINK_PKGSRCDIR.liboqs?=	../../security/liboqs

.endif	# LIBOQS_BUILDLINK3_MK

BUILDLINK_TREE+=	-liboqs
