# $NetBSD: buildlink3.mk,v 1.2 2004/03/05 19:25:10 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
AT_SPI_BUILDLINK3_MK:=	${AT_SPI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	at-spi
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nat-spi}
BUILDLINK_PACKAGES+=	at-spi

.if !empty(AT_SPI_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.at-spi?=	at-spi>=1.3.8nb1
BUILDLINK_PKGSRCDIR.at-spi?=	../../devel/at-spi

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gail/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif	# AT_SPI_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
