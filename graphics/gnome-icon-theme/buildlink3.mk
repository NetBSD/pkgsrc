# $NetBSD: buildlink3.mk,v 1.3 2004/09/21 16:48:38 jmmv Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
GNOME_ICON_THEME_BUILDLINK3_MK:=	${GNOME_ICON_THEME_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-icon-theme
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-icon-theme}
BUILDLINK_PACKAGES+=	gnome-icon-theme

.if !empty(GNOME_ICON_THEME_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnome-icon-theme+=	gnome-icon-theme>=2.8.0
BUILDLINK_PKGSRCDIR.gnome-icon-theme?=	../../graphics/gnome-icon-theme

.  include "../../mk/bsd.prefs.mk"

dirs!=	${GREP} "^@dirrm" ${.CURDIR}/../../graphics/gnome-icon-theme/PLIST | \
	${CUT} -d ' ' -f 2
.  for d in ${dirs}
PRINT_PLIST_AWK+=	/^@dirrm ${d:S/\//\\\//g}$$/ \
			{ print "@comment in gnome-icon-theme: " $$0; next; }
.  endfor
.  undef d
.  undef dirs
.endif	# GNOME_ICON_THEME_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
