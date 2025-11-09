# $NetBSD: buildlink3.mk,v 1.55 2025/11/09 19:26:39 wiz Exp $

BUILDLINK_TREE+=	pidgin

.if !defined(PIDGIN_BUILDLINK3_MK)
PIDGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pidgin+=	pidgin>=2.5.1
BUILDLINK_ABI_DEPENDS.pidgin+=	pidgin>=2.14.14nb4
BUILDLINK_PKGSRCDIR.pidgin?=	../../chat/pidgin

BUILDLINK_INCDIRS.pidgin+=	include/pidgin

.include "../../chat/libpurple/buildlink3.mk"
.endif # PIDGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-pidgin
