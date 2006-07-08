# $NetBSD: buildlink3.mk,v 1.14 2006/07/08 23:10:41 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
AT_SPI_BUILDLINK3_MK:=	${AT_SPI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	at-spi
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nat-spi}
BUILDLINK_PACKAGES+=	at-spi
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}at-spi

.if !empty(AT_SPI_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.at-spi+=	at-spi>=1.6.0
BUILDLINK_ABI_DEPENDS.at-spi+=	at-spi>=1.7.7nb1
BUILDLINK_PKGSRCDIR.at-spi?=	../../devel/at-spi
.endif	# AT_SPI_BUILDLINK3_MK

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gail/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
