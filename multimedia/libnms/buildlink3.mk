# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:04 joerg Exp $

BUILDLINK_TREE+=	libnms

.if !defined(LIBNMS_BUILDLINK3_MK)
LIBNMS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnms+=	libnms>=0.6.0
BUILDLINK_PKGSRCDIR.libnms?=	../../multimedia/libnms
.endif # LIBNMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnms
