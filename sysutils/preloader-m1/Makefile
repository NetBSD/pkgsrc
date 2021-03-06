# $NetBSD: Makefile,v 1.1 2021/03/06 20:14:30 jmcneill Exp $

PKGNAME=	preloader-m1-0.0.20210220
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=corellium/}
GITHUB_PROJECT=	preloader-m1
GITHUB_TAG=	32c0b02c2a3d78e90bb4712094fa26d1b6ac6cae
DISTNAME=	preloader-m1-${GITHUB_TAG}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/corellium/preloader-m1/
COMMENT=	Preloader for OS images on Apple M1 SoCs
LICENSE=	modified-bsd

USE_TOOLS+=	gmake

BUILD_DEPENDS+=	cross-aarch64-none-elf-gcc-[0-9]*:../../cross/aarch64-none-elf-gcc
MAKE_ENV+=	CROSS_COMPILE=${PREFIX}/cross-aarch64-none-elf/bin/aarch64-none-elf-
BUILD_TARGET=	machopack preboot.bin

INSTALLATION_DIRS=	bin share/preloader-m1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/machopack ${DESTDIR}${PREFIX}/bin/machopack
	${INSTALL_DATA} ${WRKSRC}/preboot.bin ${DESTDIR}${PREFIX}/share/preloader-m1

.include "../../mk/bsd.pkg.mk"
