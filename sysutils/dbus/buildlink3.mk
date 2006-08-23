# $NetBSD: buildlink3.mk,v 1.10 2006/08/23 09:44:27 jmmv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
DBUS_BUILDLINK3_MK:=	${DBUS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	dbus
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ndbus}
BUILDLINK_PACKAGES+=	dbus
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}dbus

.if !empty(DBUS_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.dbus+=	dbus>=0.91
BUILDLINK_PKGSRCDIR.dbus?=	../../sysutils/dbus

PRINT_PLIST_AWK+=	/^@dirrm include\/dbus-1.0\/dbus$$/ \
				{ print "@comment in dbus: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/dbus-1\/services/ \
				{ print "@comment in dbus: " $$0; next }
.endif	# DBUS_BUILDLINK3_MK

.include "../../textproc/expat/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
