# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 01:25:25 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libgnomecanvas.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBGNOMECANVAS_BUILDLINK3_MK:=	${LIBGNOMECANVAS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgnomecanvas
.endif

.if !empty(LIBGNOMECANVAS_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libgnomecanvas
BUILDLINK_DEPENDS.libgnomecanvas+=	libgnomecanvas>=2.4.0nb1
BUILDLINK_PKGSRCDIR.libgnomecanvas?=	../../graphics/libgnomecanvas

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif # LIBGNOMECANVAS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
