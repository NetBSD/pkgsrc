# $NetBSD: buildlink3.mk,v 1.2 2004/10/03 00:13:25 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
BONOBO_BUILDLINK3_MK:=	${BONOBO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	bonobo
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nbonobo}
BUILDLINK_PACKAGES+=	bonobo

.if !empty(BONOBO_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.bonobo+=	bonobo>=1.0.18nb7
BUILDLINK_RECOMMENDED.bonobo+=	bonobo>=1.0.18nb8
BUILDLINK_PKGSRCDIR.bonobo?=	../../devel/bonobo
.endif	# BONOBO_BUILDLINK3_MK

.include "../../graphics/gdk-pixbuf-gnome/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../print/gnome-print/buildlink3.mk"
.include "../../textproc/libxml/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/oaf/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
