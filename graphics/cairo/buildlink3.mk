# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/02/03 12:16:43 recht Exp $
#
# This Makefile fragment is included by packages that use cairo.
#
# This file was created automatically using createbuildlink-3.0.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
CAIRO_BUILDLINK3_MK:=	${CAIRO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	cairo
.endif

.if !empty(CAIRO_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			cairo
BUILDLINK_DEPENDS.cairo?=		cairo>=0.1.17
BUILDLINK_PKGSRCDIR.cairo?=		../../graphics/cairo

BUILDLINK_DEPENDS.freetype2=  freetype2>=2.1.5

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libpixman/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"

.endif # CAIRO_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
