# $NetBSD: buildlink3.mk,v 1.2 2004/10/03 00:14:54 tv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
KDEGRAPHICS_BUILDLINK3_MK:=	${KDEGRAPHICS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	kdegraphics
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nkdegraphics}
BUILDLINK_PACKAGES+=	kdegraphics

.if !empty(KDEGRAPHICS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.kdegraphics+=	kdegraphics>=3.2.0
BUILDLINK_RECOMMENDED.kdegraphics?=	kdegraphics>=3.3.0nb1
BUILDLINK_PKGSRCDIR.kdegraphics?=	../../graphics/kdegraphics3
.endif	# KDEGRAPHICS_BUILDLINK3_MK

.include "../../converters/fribidi/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
