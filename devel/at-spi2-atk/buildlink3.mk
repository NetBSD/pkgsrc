# $NetBSD: buildlink3.mk,v 1.2 2012/11/13 21:44:23 adam Exp $

BUILDLINK_TREE+=	at-spi2-atk

.if !defined(AT_SPI2_ATK_BUILDLINK3_MK)
AT_SPI2_ATK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.at-spi2-atk+=	at-spi2-atk>=2.6.1
BUILDLINK_PKGSRCDIR.at-spi2-atk?=	../../devel/at-spi2-atk

.include "../../devel/at-spi2-core/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif	# AT_SPI2_ATK_BUILDLINK3_MK

BUILDLINK_TREE+=	-at-spi2-atk
