# $NetBSD: Makefile,v 1.2 2020/03/18 17:52:39 joerg Exp $
#

DISTNAME=	picasm114
PKGNAME=	${DISTNAME:S/picasm/picasm-/}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://nsa.kpu-m.ac.jp/gijutu/kousaku/man-pic/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
# Mirror of the latest release notes
HOMEPAGE=	http://nsa.kpu-m.ac.jp/gijutu/kousaku/man-pic/picasm.html
COMMENT=	Assembler for Microchip PIC16Cxx microcontrollers
LICENSE=	mit

BUILD_TARGET=		picasm
BUILD_MAKE_FLAGS=	CC=${CC:Q}
# We need to construct -DBUILTIN_INCLUDE1=\"/usr/pkg/share/picasm/include\"
# in order to process symbol correctly to the preprocessor
BUILD_MAKE_FLAGS=	DEFS=-DBUILTIN_INCLUDE1=\\\"${PREFIX}/share/picasm/include\\\"

INSTALLATION_DIRS=	bin share/examples/picasm share/doc/picasm \
			share/picasm/include

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/picasm ${DESTDIR}${PREFIX}/bin

.for file in example.asm morse.asm morse.i pic16f84.i picmac.i
	${INSTALL_DATA} ${WRKSRC}/examples/${file} \
		${DESTDIR}${PREFIX}/share/examples/picasm
.endfor

	${INSTALL_DATA} ${WRKSRC}/device_definitions/*.i \
		${DESTDIR}${PREFIX}/share/picasm/include

.for file in picasm.txt  picasm.html
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${PREFIX}/share/doc/picasm
.endfor

.include "../../mk/bsd.pkg.mk"
