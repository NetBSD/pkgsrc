# $NetBSD: buildlink3.mk,v 1.39 2016/04/11 19:01:33 ryoon Exp $

BUILDLINK_TREE+=	empathy

.if !defined(EMPATHY_BUILDLINK3_MK)
EMPATHY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.empathy+=	empathy>=2.24.1nb1
BUILDLINK_ABI_DEPENDS.empathy+=	empathy>=2.34.0nb47
BUILDLINK_PKGSRCDIR.empathy?=	../../chat/empathy

.include "../../devel/glib2/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # EMPATHY_BUILDLINK3_MK

BUILDLINK_TREE+=	-empathy
