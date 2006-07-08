# $NetBSD: buildlink3.mk,v 1.15 2006/07/08 23:10:49 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GUCHARMAP_BUILDLINK3_MK:=	${GUCHARMAP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gucharmap
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngucharmap}
BUILDLINK_PACKAGES+=	gucharmap
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gucharmap

.if !empty(GUCHARMAP_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gucharmap+=	gucharmap>=1.4.0
BUILDLINK_ABI_DEPENDS.gucharmap+=	gucharmap>=1.6.0nb1
BUILDLINK_PKGSRCDIR.gucharmap?=	../../fonts/gucharmap
.endif	# GUCHARMAP_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
