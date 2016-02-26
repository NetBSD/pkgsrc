# $NetBSD: buildlink3.mk,v 1.1 2016/02/26 15:52:08 fhajny Exp $

BUILDLINK_TREE+=	wiredtiger

.if !defined(WIREDTIGER_BUILDLINK3_MK)
WIREDTIGER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wiredtiger+=	wiredtiger>=2.7.0
BUILDLINK_PKGSRCDIR.wiredtiger?=	../../databases/wiredtiger
.endif # WIREDTIGER_BUILDLINK3_MK

BUILDLINK_TREE+=	-wiredtiger
