# $NetBSD: buildlink3.mk,v 1.1 2014/07/26 20:27:47 schnoebe Exp $

BUILDLINK_TREE+=	xentools42

.if !defined(XENTOOLS42_BUILDLINK3_MK)
XENTOOLS42_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xentools42+=	xentools42>=4.2
BUILDLINK_PKGSRCDIR.xentools42?=	../../sysutils/xentools42
.endif # XENTOOLS42_BUILDLINK3_MK

BUILDLINK_TREE+=	-xentools42
