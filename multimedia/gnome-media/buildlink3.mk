# $NetBSD: buildlink3.mk,v 1.2 2007/09/21 13:04:06 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_MEDIA_BUILDLINK3_MK:=	${GNOME_MEDIA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-media
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-media}
BUILDLINK_PACKAGES+=	gnome-media
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gnome-media

.if !empty(GNOME_MEDIA_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gnome-media+=		gnome-media>=2.12.0nb1
BUILDLINK_ABI_DEPENDS.gnome-media?=	gnome-media>=2.18.0nb1
BUILDLINK_PKGSRCDIR.gnome-media?=	../../multimedia/gnome-media
.endif	# GNOME_MEDIA_BUILDLINK3_MK

.include "../../devel/GConf-ui/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
