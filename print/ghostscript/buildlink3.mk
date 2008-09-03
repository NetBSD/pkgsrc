# $NetBSD: buildlink3.mk,v 1.1 2008/09/03 21:31:12 markd Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GHOSTSCRIPT_BUILDLINK3_MK:=	${GHOSTSCRIPT_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	ghostscript
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nghostscript}
BUILDLINK_PACKAGES+=	ghostscript
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}ghostscript

.if ${GHOSTSCRIPT_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.ghostscript+=	ghostscript>=8.63nb1
BUILDLINK_PKGSRCDIR.ghostscript?=	../../print/ghostscript
.endif	# GHOSTSCRIPT_BUILDLINK3_MK

.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

pkgbase := ghostscript
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.ghostscript:Mcups)
.include "../../print/cups/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ghostscript:Mfontconfig)
.include "../../fonts/fontconfig/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ghostscript:Mx11)
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.endif

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
