# $NetBSD: buildlink3.mk,v 1.2 2004/10/03 00:14:51 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GIMP_BUILDLINK3_MK:=	${GIMP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gimp
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngimp}
BUILDLINK_PACKAGES+=	gimp

.if !empty(GIMP_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gimp+=	gimp>=2.0.1nb1
BUILDLINK_RECOMMENDED.gimp+=	gimp>=2.0.5nb1
BUILDLINK_PKGSRCDIR.gimp?=	../../graphics/gimp
.endif	# GIMP_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/aalib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/libwmf/buildlink3.mk"
.include "../../print/gimp-print-lib/buildlink3.mk"
.include "../../www/libgtkhtml/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
