# $NetBSD: buildlink3.mk,v 1.5 2005/05/25 22:36:39 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_PILOT_BUILDLINK3_MK:=	${GNOME_PILOT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-pilot
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-pilot}
BUILDLINK_PACKAGES+=	gnome-pilot

.if !empty(GNOME_PILOT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnome-pilot?=		gnome-pilot>=2.0.12
BUILDLINK_PKGSRCDIR.gnome-pilot?=	../../comms/gnome-pilot
.endif	# GNOME_PILOT_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../comms/pilot-link-libs/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
