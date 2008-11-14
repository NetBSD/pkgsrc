# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/11/14 22:58:06 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBTELEPATHY_BUILDLINK3_MK:=	${LIBTELEPATHY_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libtelepathy
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibtelepathy}
BUILDLINK_PACKAGES+=	libtelepathy
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libtelepathy

.if ${LIBTELEPATHY_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libtelepathy+=	libtelepathy>=0.3.3
BUILDLINK_PKGSRCDIR.libtelepathy?=	../../chat/libtelepathy
.endif	# LIBTELEPATHY_BUILDLINK3_MK

.include "../../chat/telepathy-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
