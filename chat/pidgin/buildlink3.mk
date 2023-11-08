# $NetBSD: buildlink3.mk,v 1.49 2023/11/08 13:18:16 wiz Exp $

BUILDLINK_TREE+=	pidgin

.if !defined(PIDGIN_BUILDLINK3_MK)
PIDGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pidgin+=	pidgin>=2.5.1
BUILDLINK_ABI_DEPENDS.pidgin+=	pidgin>=2.14.12nb5
BUILDLINK_PKGSRCDIR.pidgin?=	../../chat/pidgin

.include "../../chat/libpurple/buildlink3.mk"
.endif # PIDGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-pidgin
