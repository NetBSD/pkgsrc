# $NetBSD: buildlink3.mk,v 1.2 2012/03/03 00:12:01 wiz Exp $

BUILDLINK_TREE+=	at-spi2-core

.if !defined(AT_SPI2_CORE_BUILDLINK3_MK)
AT_SPI2_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.at-spi2-core+=	at-spi2-core>=2.3.2
BUILDLINK_ABI_DEPENDS.at-spi2-core+=	at-spi2-core>=2.3.5nb1
BUILDLINK_PKGSRCDIR.at-spi2-core?=	../../devel/at-spi2-core

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.endif # AT_SPI2_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-at-spi2-core
