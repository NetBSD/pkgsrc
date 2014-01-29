# $NetBSD: buildlink3.mk,v 1.16 2014/01/29 13:01:53 ryoon Exp $

BUILDLINK_TREE+=	dbus

.if !defined(DBUS_BUILDLINK3_MK)
DBUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dbus+=	dbus>=0.91
BUILDLINK_PKGSRCDIR.dbus?=	../../sysutils/dbus

.if defined(USE_DBUS-ARCH-DEPS_H)
.  if !empty(USE_DBUS-ARCH-DEPS_H:M[yY][eE][sS])
BUILDLINK_INCDIRS.dbus+=	lib/dbus-1.0/include/dbus
BUILDLINK_FNAME_TRANSFORM.dbus+=	-e "s|lib/dbus-1.0/||"
.  endif
.endif

.include "../../textproc/expat/buildlink3.mk"
.endif # DBUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-dbus
