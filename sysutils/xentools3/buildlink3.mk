# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:25:26 joerg Exp $

BUILDLINK_TREE+=	xentools3

.if !defined(XENTOOLS3_BUILDLINK3_MK)
XENTOOLS3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xentools3+=	xentools3>=3.1.3
BUILDLINK_PKGSRCDIR.xentools3?=	../../sysutils/xentools3
.endif # XENTOOLS3_BUILDLINK3_MK

BUILDLINK_TREE+=	-xentools3
