# $NetBSD: buildlink3.mk,v 1.6 2006/01/24 07:32:14 wiz Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
GNOME_ICON_THEME_BUILDLINK3_MK:=	${GNOME_ICON_THEME_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-icon-theme
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-icon-theme}
BUILDLINK_PACKAGES+=	gnome-icon-theme

.if !empty(GNOME_ICON_THEME_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnome-icon-theme+=	gnome-icon-theme>=2.8.0
BUILDLINK_RECOMMENDED.gnome-icon-theme?=	gnome-icon-theme>=2.12.1nb1
BUILDLINK_PKGSRCDIR.gnome-icon-theme?=	../../graphics/gnome-icon-theme

# intltool-{extract,merge,update} are Perl scripts included in the sources
# of packages that use gnome-icon-theme and are executed during build.
#
USE_TOOLS+=	perl

.  include "../../mk/bsd.prefs.mk"

dirs!=	${GREP} "^@dirrm" ${.CURDIR}/../../graphics/gnome-icon-theme/PLIST | \
	${CUT} -d ' ' -f 2
.  for d in ${dirs}
PRINT_PLIST_AWK+=	/^@dirrm ${d:S/\//\\\//g}$$/ \
			{ print "@comment in gnome-icon-theme: " $$0; next; }
.  endfor
.  undef dirs
.endif	# GNOME_ICON_THEME_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
