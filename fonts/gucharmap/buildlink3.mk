# $NetBSD: buildlink3.mk,v 1.22 2009/03/15 19:42:26 jmcneill Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GUCHARMAP_BUILDLINK3_MK:=	${GUCHARMAP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gucharmap
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngucharmap}
BUILDLINK_PACKAGES+=	gucharmap
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gucharmap

.if !empty(GUCHARMAP_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gucharmap+=	gucharmap>=2.24.1
BUILDLINK_PKGSRCDIR.gucharmap?=	../../fonts/gucharmap
.endif	# GUCHARMAP_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
