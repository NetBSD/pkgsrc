# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 06:22:08 xtraeme Exp $
#
# This Makefile fragment is included by packages that use librsvg2.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBRSVG2_BUILDLINK3_MK:=	${LIBRSVG2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	librsvg2
.endif

.if !empty(LIBRSVG2_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			librsvg2
BUILDLINK_DEPENDS.librsvg2+=		librsvg2>=2.5.0nb4
BUILDLINK_PKGSRCDIR.librsvg2?=		../../graphics/librsvg2

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../textproc/libcroco/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif # LIBRSVG2_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
