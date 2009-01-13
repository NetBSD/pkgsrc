# $NetBSD: buildlink3.mk,v 1.1 2009/01/13 09:08:18 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EMPATHY_BUILDLINK3_MK:=	${EMPATHY_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	empathy
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nempathy}
BUILDLINK_PACKAGES+=	empathy
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}empathy

.if ${EMPATHY_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.empathy+=	empathy>=2.24.1nb1
BUILDLINK_PKGSRCDIR.empathy?=	../../chat/empathy
.endif	# EMPATHY_BUILDLINK3_MK

.include "../../chat/telepathy-mission-control/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
