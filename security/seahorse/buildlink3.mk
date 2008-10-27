# $NetBSD: buildlink3.mk,v 1.12 2008/10/27 16:51:59 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SEAHORSE_BUILDLINK3_MK:=	${SEAHORSE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	seahorse
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nseahorse}
BUILDLINK_PACKAGES+=	seahorse
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}seahorse

.if ${SEAHORSE_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.seahorse+=	seahorse>=2.24.1
BUILDLINK_PKGSRCDIR.seahorse?=	../../security/seahorse
.endif	# SEAHORSE_BUILDLINK3_MK

.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
