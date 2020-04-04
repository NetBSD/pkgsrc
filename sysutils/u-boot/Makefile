# $NetBSD: Makefile,v 1.29 2020/04/04 15:20:35 thorpej Exp $
#

.include "../../sysutils/u-boot/u-boot-version.mk"

DISTNAME=	u-boot-${UBOOT_VERSION}
PKGREVISION=	9
CATEGORIES=	meta-pkgs sysutils u-boot
MASTER_SITES=	# empty

MAINTAINER=	jmcneill@NetBSD.org
HOMEPAGE=	https://www.denx.de/wiki/U-Boot
COMMENT=	Das U-Boot, the Universal Boot Loader (meta-package)

META_PACKAGE=	yes

.include "options.mk"
.include "../../mk/bsd.prefs.mk"

DEPENDS+=	u-boot-a10-olinuxino-lime-[0-9]*:../../sysutils/u-boot-a10-olinuxino-lime
DEPENDS+=	u-boot-a20-olinuxino-lime2-[0-9]*:../../sysutils/u-boot-a20-olinuxino-lime2
DEPENDS+=	u-boot-a20-olinuxino-lime2-emmc-[0-9]*:../../sysutils/u-boot-a20-olinuxino-lime2-emmc
DEPENDS+=	u-boot-a20-olinuxino-micro-emmc-[0-9]*:../../sysutils/u-boot-a20-olinuxino-micro-emmc
DEPENDS+=	u-boot-bananapi-m2-zero-[0-9]*:../../sysutils/u-boot-bananapi-m2-zero
DEPENDS+=	u-boot-bananapi-m3-[0-9]*:../../sysutils/u-boot-bananapi-m3
DEPENDS+=	u-boot-bananapi-p2-zero-[0-9]*:../../sysutils/u-boot-bananapi-p2-zero
DEPENDS+=	u-boot-bananapi-[0-9]*:../../sysutils/u-boot-bananapi
DEPENDS+=	u-boot-bananapro-[0-9]*:../../sysutils/u-boot-bananapro
DEPENDS+=	u-boot-beagleboard-[0-9]*:../../sysutils/u-boot-beagleboard
DEPENDS+=	u-boot-beagleboneblack-[0-9]*:../../sysutils/u-boot-beagleboneblack
DEPENDS+=	u-boot-beaglebonewhite-[0-9]*:../../sysutils/u-boot-beaglebonewhite
DEPENDS+=	u-boot-chip-pro-[0-9]*:../../sysutils/u-boot-chip-pro
DEPENDS+=	u-boot-chip-[0-9]*:../../sysutils/u-boot-chip
DEPENDS+=	u-boot-cubieboard2-[0-9]*:../../sysutils/u-boot-cubieboard2
DEPENDS+=	u-boot-cubieboard4-[0-9]*:../../sysutils/u-boot-cubieboard4
DEPENDS+=	u-boot-cubietruck-[0-9]*:../../sysutils/u-boot-cubietruck
DEPENDS+=	u-boot-cubietruck-plus-[0-9]*:../../sysutils/u-boot-cubietruck-plus
DEPENDS+=	u-boot-de0-nanosoc-[0-9]*:../../sysutils/u-boot-de0-nanosoc
DEPENDS+=	u-boot-hummingbird-a31-[0-9]*:../../sysutils/u-boot-hummingbird-a31
DEPENDS+=	u-boot-jetson-tk1-[0-9]*:../../sysutils/u-boot-jetson-tk1
DEPENDS+=	u-boot-jetson-tx1-[0-9]*:../../sysutils/u-boot-jetson-tx1
DEPENDS+=	u-boot-jetson-tx2-[0-9]*:../../sysutils/u-boot-jetson-tx2
DEPENDS+=	u-boot-lamobo-r1-[0-9]*:../../sysutils/u-boot-lamobo-r1
.if !empty(PKG_OPTIONS:Mamlogic-meson)
DEPENDS+=	u-boot-libretech-cc-[0-9]*:../../sysutils/u-boot-libretech-cc
.endif
DEPENDS+=	u-boot-nanopi-duo2-[0-9]*:../../sysutils/u-boot-nanopi-duo2
DEPENDS+=	u-boot-nanopi-m1-[0-9]*:../../sysutils/u-boot-nanopi-m1
DEPENDS+=	u-boot-nanopi-neo-plus2-[0-9]*:../../sysutils/u-boot-nanopi-neo-plus2
DEPENDS+=	u-boot-nanopi-neo-[0-9]*:../../sysutils/u-boot-nanopi-neo
DEPENDS+=	u-boot-nanopi-neo2-[0-9]*:../../sysutils/u-boot-nanopi-neo2
DEPENDS+=	u-boot-nanopi-r1-[0-9]*:../../sysutils/u-boot-nanopi-r1
.if !empty(PKG_OPTIONS:Mamlogic-meson)
DEPENDS+=	u-boot-odroid-c2-[0-9]*:../../sysutils/u-boot-odroid-c2
.endif
DEPENDS+=	u-boot-odroid-xu3-[0-9]*:../../sysutils/u-boot-odroid-xu3
DEPENDS+=	u-boot-orangepi-2-[0-9]*:../../sysutils/u-boot-orangepi-2
DEPENDS+=	u-boot-orangepi-lite-[0-9]*:../../sysutils/u-boot-orangepi-lite
DEPENDS+=	u-boot-orangepi-lite2-[0-9]*:../../sysutils/u-boot-orangepi-lite2
DEPENDS+=	u-boot-orangepi-one-[0-9]*:../../sysutils/u-boot-orangepi-one
DEPENDS+=	u-boot-orangepi-plus2e-[0-9]*:../../sysutils/u-boot-orangepi-plus2e
DEPENDS+=	u-boot-orangepi-zero-[0-9]*:../../sysutils/u-boot-orangepi-zero
DEPENDS+=	u-boot-orangepi-zero-plus-[0-9]*:../../sysutils/u-boot-orangepi-zero-plus
DEPENDS+=	u-boot-pine-h64-[0-9]*:../../sysutils/u-boot-pine-h64
DEPENDS+=	u-boot-pine64-[0-9]*:../../sysutils/u-boot-pine64
DEPENDS+=	u-boot-pinebook-[0-9]*:../../sysutils/u-boot-pinebook
DEPENDS+=	u-boot-pinebook-pro-[0-9]*:../../sysutils/u-boot-pinebook-pro
DEPENDS+=	u-boot-pocketchip-[0-9]*:../../sysutils/u-boot-pocketchip
DEPENDS+=	u-boot-rock64-[0-9]*:../../sysutils/u-boot-rock64
DEPENDS+=	u-boot-rockpro64-[0-9]*:../../sysutils/u-boot-rockpro64
DEPENDS+=	u-boot-rpi3-32-[0-9]*:../../sysutils/u-boot-rpi3-32
DEPENDS+=	u-boot-sopine-baseboard-[0-9]*:../../sysutils/u-boot-sopine-baseboard

.include "../../mk/bsd.pkg.mk"
