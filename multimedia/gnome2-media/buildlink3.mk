# $NetBSD: buildlink3.mk,v 1.4 2006/01/24 07:32:27 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_MEDIA_BUILDLINK3_MK:=	${GNOME_MEDIA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-media
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-media}
BUILDLINK_PACKAGES+=	gnome-media

.if !empty(GNOME_MEDIA_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnome-media+=		gnome-media>=2.12.0nb1
BUILDLINK_RECOMMENDED.gnome-media?=	gnome-media>=2.12.0nb4
BUILDLINK_PKGSRCDIR.gnome-media?=	../../multimedia/gnome2-media
.endif	# GNOME_MEDIA_BUILDLINK3_MK

.include "../../devel/GConf2-ui/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
