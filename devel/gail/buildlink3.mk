# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 03:04:28 xtraeme Exp $
#
# This Makefile fragment is included by packages that use gail.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GAIL_BUILDLINK3_MK:=	${GAIL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gail
.endif

.if !empty(GAIL_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			gail
BUILDLINK_DEPENDS.gail+=		gail>=1.4.1nb1
BUILDLINK_PKGSRCDIR.gail?=		../../devel/gail

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif # GAIL_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
