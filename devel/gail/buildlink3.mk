# $NetBSD: buildlink3.mk,v 1.8 2006/02/05 23:08:42 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GAIL_BUILDLINK3_MK:=	${GAIL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gail
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngail}
BUILDLINK_PACKAGES+=	gail

.if !empty(GAIL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gail+=	gail>=1.8.0
BUILDLINK_RECOMMENDED.gail+=	gail>=1.8.8nb2
BUILDLINK_PKGSRCDIR.gail?=	../../devel/gail
.endif	# GAIL_BUILDLINK3_MK

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
