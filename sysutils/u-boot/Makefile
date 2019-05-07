# $NetBSD: Makefile,v 1.11 2019/05/07 14:05:36 thorpej Exp $
#

.include "../../sysutils/u-boot/u-boot-version.mk"

DISTNAME=	u-boot-${UBOOT_VERSION}
PKGREVISION=	2
CATEGORIES=	meta-pkgs sysutils u-boot
MASTER_SITES=	# empty

MAINTAINER=	jmcneill@NetBSD.org
HOMEPAGE=	https://www.denx.de/wiki/U-Boot
COMMENT=	Das U-Boot, the Universal Boot Loader (meta-package)

DEPENDS+=	u-boot-a10-olinuxino-lime-[0-9]*:../../sysutils/u-boot-a10-olinuxino-lime
DEPENDS+=	u-boot-bananapi-m3-[0-9]*:../../sysutils/u-boot-bananapi-m3
DEPENDS+=	u-boot-bananapi-[0-9]*:../../sysutils/u-boot-bananapi
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
DEPENDS+=	u-boot-libretech-cc-[0-9]*:../../sysutils/u-boot-libretech-cc
DEPENDS+=	u-boot-nanopi-m1-[0-9]*:../../sysutils/u-boot-nanopi-m1
DEPENDS+=	u-boot-nanopi-neo-plus2-[0-9]*:../../sysutils/u-boot-nanopi-neo-plus2
DEPENDS+=	u-boot-nanopi-neo-[0-9]*:../../sysutils/u-boot-nanopi-neo
DEPENDS+=	u-boot-nanopi-neo2-[0-9]*:../../sysutils/u-boot-nanopi-neo2
DEPENDS+=	u-boot-odroid-xu3-[0-9]*:../../sysutils/u-boot-odroid-xu3
DEPENDS+=	u-boot-orangepi-2-[0-9]*:../../sysutils/u-boot-orangepi-2
DEPENDS+=	u-boot-orangepi-one-[0-9]*:../../sysutils/u-boot-orangepi-one
DEPENDS+=	u-boot-orangepi-plus2e-[0-9]*:../../sysutils/u-boot-orangepi-plus2e
DEPENDS+=	u-boot-orangepi-zero-[0-9]*:../../sysutils/u-boot-orangepi-zero
DEPENDS+=	u-boot-orangepi-zero-plus-[0-9]*:../../sysutils/u-boot-orangepi-zero-plus
DEPENDS+=	u-boot-pine-h64-[0-9]*:../../sysutils/u-boot-pine-h64
DEPENDS+=	u-boot-pine64-[0-9]*:../../sysutils/u-boot-pine64
DEPENDS+=	u-boot-pinebook-[0-9]*:../../sysutils/u-boot-pinebook
DEPENDS+=	u-boot-pocketchip-[0-9]*:../../sysutils/u-boot-pocketchip
DEPENDS+=	u-boot-sopine-baseboard-[0-9]*:../../sysutils/u-boot-sopine-baseboard

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
