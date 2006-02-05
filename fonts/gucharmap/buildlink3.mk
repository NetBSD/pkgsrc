# $NetBSD: buildlink3.mk,v 1.10 2006/02/05 23:09:09 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GUCHARMAP_BUILDLINK3_MK:=	${GUCHARMAP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gucharmap
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngucharmap}
BUILDLINK_PACKAGES+=	gucharmap

.if !empty(GUCHARMAP_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gucharmap+=	gucharmap>=1.4.0
BUILDLINK_RECOMMENDED.gucharmap+=	gucharmap>=1.4.4nb3
BUILDLINK_PKGSRCDIR.gucharmap?=	../../fonts/gucharmap
.endif	# GUCHARMAP_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
