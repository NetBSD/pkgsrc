# $NetBSD: buildlink3.mk,v 1.2 2004/10/03 00:12:56 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GUPPI_BUILDLINK3_MK:=	${GUPPI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	guppi
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nguppi}
BUILDLINK_PACKAGES+=	guppi

.if !empty(GUPPI_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.guppi+=	guppi>=0.40.3nb8
BUILDLINK_RECOMMENDED.guppi+=	guppi>=0.40.3nb11
BUILDLINK_PKGSRCDIR.guppi?=	../../math/guppi
.endif	# GUPPI_BUILDLINK3_MK

.include "../../devel/bonobo/buildlink3.mk"
.include "../../devel/gal/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../lang/guile14/buildlink3.mk"
.include "../../print/gnome-print/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
