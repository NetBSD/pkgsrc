# $NetBSD: buildlink3.mk,v 1.39 2020/06/02 08:22:32 adam Exp $

BUILDLINK_TREE+=	pidgin

.if !defined(PIDGIN_BUILDLINK3_MK)
PIDGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pidgin+=	pidgin>=2.5.1
BUILDLINK_ABI_DEPENDS.pidgin+=	pidgin>=2.13.0nb10
BUILDLINK_PKGSRCDIR.pidgin?=	../../chat/pidgin

.include "../../chat/libpurple/buildlink3.mk"
.endif # PIDGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-pidgin
