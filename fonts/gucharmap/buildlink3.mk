# $NetBSD: buildlink3.mk,v 1.3 2004/03/05 19:25:12 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GUCHARMAP_BUILDLINK3_MK:=	${GUCHARMAP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gucharmap
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngucharmap}
BUILDLINK_PACKAGES+=	gucharmap

.if !empty(GUCHARMAP_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gucharmap+=	gucharmap>=1.2.0nb2
BUILDLINK_PKGSRCDIR.gucharmap?=	../../fonts/gucharmap

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif	# GUCHARMAP_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
