# $NetBSD: buildlink3.mk,v 1.1 2017/01/20 11:00:50 fhajny Exp $

BUILDLINK_TREE+=	oce

.if !defined(OCE_BUILDLINK3_MK)
OCE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.oce+=	oce>=0.18
BUILDLINK_PKGSRCDIR.oce?=	../../cad/oce

BUILDLINK_INCDIRS.oce+=	include/oce

.if !empty(PKG_OPTIONS:Mx11)
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.endif
.endif	# OCE_BUILDLINK3_MK

BUILDLINK_TREE+=	-oce
