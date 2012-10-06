# $NetBSD: buildlink3.mk,v 1.32 2012/10/06 08:46:41 ryoon Exp $

BUILDLINK_TREE+=	pidgin

.if !defined(PIDGIN_BUILDLINK3_MK)
PIDGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pidgin+=	pidgin>=2.5.1
BUILDLINK_ABI_DEPENDS.pidgin+=	pidgin>=2.10.6nb3
BUILDLINK_PKGSRCDIR.pidgin?=	../../chat/pidgin

.include "../../chat/libpurple/buildlink3.mk"
.endif # PIDGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-pidgin
