# $NetBSD: buildlink3.mk,v 1.3 2004/10/03 00:14:51 tv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GIMP_BASE_BUILDLINK3_MK:=	${GIMP_BASE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gimp-base
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngimp-base}
BUILDLINK_PACKAGES+=	gimp-base

.if !empty(GIMP_BASE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gimp-base+=	gimp-base>=1.2.5nb2
BUILDLINK_RECOMMENDED.gimp-base+=	gimp-base>=1.2.5nb3
BUILDLINK_PKGSRCDIR.gimp-base?=	../../graphics/gimp1-base
.endif	# GIMP_BASE_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../multimedia/mpeg-lib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
