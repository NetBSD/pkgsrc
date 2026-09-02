# $NetBSD: buildlink3.mk,v 1.57 2026/09/02 19:01:09 wiz Exp $

BUILDLINK_TREE+=	pidgin

.if !defined(PIDGIN_BUILDLINK3_MK)
PIDGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pidgin+=	pidgin>=2.5.1
BUILDLINK_ABI_DEPENDS.pidgin+=	pidgin>=2.14.14nb7
BUILDLINK_PKGSRCDIR.pidgin?=	../../chat/pidgin

BUILDLINK_INCDIRS.pidgin+=	include/pidgin

.include "../../chat/libpurple/buildlink3.mk"
.endif # PIDGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-pidgin
