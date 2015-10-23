# $NetBSD: Makefile,v 1.2 2015/10/23 11:01:24 tnn Exp $
#

VERSION=	20150915
DISTNAME=	sunxi-tools-${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=linux-sunxi/}
GITHUB_PROJECT=	sunxi-tools
GITHUB_TAG=	568c7a0e81fc5d52189710c6d832677aa8770b16

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://linux-sunxi.org/
COMMENT=	Tools to help hacking Allwinner A10 (and successors) devices
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin libdata/sunxi-tools

do-install:
.for f in fexc fel pio bootinfo phoenix_info
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/bin/${f}
.endfor
.for f in bin2fex fex2bin
	${LN} ${DESTDIR}${PREFIX}/bin/fexc ${DESTDIR}${PREFIX}/bin/${f}
.endfor
.for f in fel-gpio
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/bin/${f}
.endfor
.for f in fel-pio.bin fel-sdboot.sunxi ramboot.scr fel-pio.nm jtag-loop.sunxi ramboot.uboot-sh
	${INSTALL_DATA} ${WRKSRC}/bin/${f} ${DESTDIR}${PREFIX}/libdata/sunxi-tools/${f}
.endfor

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
