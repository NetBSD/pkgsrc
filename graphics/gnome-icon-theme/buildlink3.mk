# $NetBSD: buildlink3.mk,v 1.1 2004/04/01 18:29:19 jmmv Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
GNOME_ICON_THEME_BUILDLINK3_MK:=	${GNOME_ICON_THEME_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-icon-theme
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-icon-theme}
BUILDLINK_PACKAGES+=	gnome-icon-theme

.if !empty(GNOME_ICON_THEME_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnome-icon-theme+=	gnome-icon-theme>=1.2.0
BUILDLINK_PKGSRCDIR.gnome-icon-theme?=	../../graphics/gnome-icon-theme
.endif	# GNOME_ICON_THEME_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
