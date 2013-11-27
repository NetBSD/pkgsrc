# $NetBSD: buildlink3.mk,v 1.1 2013/11/27 17:09:57 khorben Exp $

BUILDLINK_TREE+=	xchat

.if !defined(XCHAT_BUILDLINK3_MK)
XCHAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xchat+=	xchat>=2.8.8
BUILDLINK_ABI_DEPENDS.xchat+=	xchat>=2.8.8
BUILDLINK_PKGSRCDIR.xchat?=	../../chat/xchat

.endif # XCHAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-xchat
