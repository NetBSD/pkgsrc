# $NetBSD: buildlink3.mk,v 1.14 2025/01/12 19:23:00 riastradh Exp $

BUILDLINK_TREE+=	at-spi2-core

.if !defined(AT_SPI2_CORE_BUILDLINK3_MK)
AT_SPI2_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.at-spi2-core+=	at-spi2-core>=2.3.2
BUILDLINK_ABI_DEPENDS.at-spi2-core+=	at-spi2-core>=2.54.0nb4
BUILDLINK_PKGSRCDIR.at-spi2-core?=	../../devel/at-spi2-core

pkgbase:= at-spi2-core
.include "../../mk/pkg-build-options.mk"

.include "../../devel/glib2/buildlink3.mk"

.if ${PKG_BUILD_OPTIONS.at-spi2-core:Mdbus}
.include "../../sysutils/dbus/buildlink3.mk"
.endif

.endif # AT_SPI2_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-at-spi2-core
