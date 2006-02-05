# $NetBSD: buildlink3.mk,v 1.3 2006/02/05 23:09:33 joerg Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
HICOLOR_ICON_THEME_BUILDLINK3_MK:=	${HICOLOR_ICON_THEME_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	hicolor-icon-theme
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nhicolor-icon-theme}
BUILDLINK_PACKAGES+=	hicolor-icon-theme

.if !empty(HICOLOR_ICON_THEME_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.hicolor-icon-theme+=	hicolor-icon-theme>=0.4
BUILDLINK_RECOMMENDED.hicolor-icon-theme+=	hicolor-icon-theme>=0.5nb1
BUILDLINK_PKGSRCDIR.hicolor-icon-theme?=../../graphics/hicolor-icon-theme

.include "../../mk/bsd.prefs.mk"

dirs!=	${GREP} "^@dirrm" ${.CURDIR}/../../graphics/hicolor-icon-theme/PLIST | \
	${CUT} -d ' ' -f 2
.  for d in ${dirs}
PRINT_PLIST_AWK+=	/^@dirrm ${d:S/\//\\\//g}$$/ \
			{ print "@comment in hicolor-icon-theme: " $$0; next; }
.  endfor
.  undef dirs
.endif	# HICOLOR_ICON_THEME_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
