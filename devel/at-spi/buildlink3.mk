# $NetBSD: buildlink3.mk,v 1.1 2004/02/13 17:02:09 jmmv Exp $
#
# This Makefile fragment is included by packages that use at-spi.
#
# This file was created automatically using createbuildlink-3.0.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
AT_SPI_BUILDLINK3_MK:=	${AT_SPI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	at-spi
.endif

.if !empty(AT_SPI_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			at-spi
BUILDLINK_DEPENDS.at-spi?=		at-spi>=1.3.8nb1
BUILDLINK_PKGSRCDIR.at-spi?=		../../devel/at-spi

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gail/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif # AT_SPI_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
