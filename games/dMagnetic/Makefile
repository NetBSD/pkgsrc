# $NetBSD: Makefile,v 1.2 2020/06/08 08:49:58 wiz Exp $

DISTNAME=		dMagnetic_0.23
PKGNAME=		${DISTNAME:S/_/-/}
CATEGORIES=		games
MASTER_SITES=		https://www.dettus.net/dMagnetic/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dettus@dettus.net
HOMEPAGE=		https://www.dettus.net/dMagnetic/
COMMENT=		Magnetic Scrolls Interpreter
LICENSE=		2-clause-bsd

INSTALLATION_DIRS=	bin share/doc/dMagnetic ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dMagnetic ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/share/doc/dMagnetic
	${INSTALL_DATA} ${WRKSRC}/dMagnetic.ini ${DESTDIR}${PREFIX}/share/doc/dMagnetic
	${INSTALL_MAN} ${WRKSRC}/dMagnetic.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/dMagneticini.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5


## The idea of this test is to check if the output is the expected one.
## for this, the md5sum is being compared.
## dMagnetic has several output modes, each one of them is tested.
do-test:
	 cd ${WRKSRC}/testcode;  if [ true \
		-a `${ECHO} Hello | ../dMagnetic -ini ../dMagnetic.ini \
			-mag minitest.mag -gfx minitest.gfx \
			-vmode none -vcols 300 -vrows 300 \
		| md5 `==0f919919290698aef854df8c75119aa8 \
		-a `${ECHO} Hello | ../dMagnetic -ini ../dMagnetic.ini \
			-mag minitest.mag -gfx minitest.gfx \
			-vmode monochrome -vcols 300 -vrows 300 \
		| md5 `==dece45b2dcc499bd4e4f4daa0d87fca5 \
		-a `${ECHO} Hello | ../dMagnetic -ini ../dMagnetic.ini \
			-mag minitest.mag -gfx minitest.gfx \
			-vmode monochrome_inv -vcols 300 -vrows 300 \
		| md5 `==0ababd938093714b51006831f6790379 \
		-a `${ECHO} Hello | ../dMagnetic -ini ../dMagnetic.ini \
			-mag minitest.mag -gfx minitest.gfx \
			-vmode low_ansi -vcols 300 -vrows 300 \
		| md5 `==54fedb8291eafbc756686ad5d0e069ee \
		-a `${ECHO} Hello | ../dMagnetic -ini ../dMagnetic.ini \
			-mag minitest.mag -gfx minitest.gfx \
			-vmode low_ansi2 -vcols 300 -vrows 300 \
		| md5 `==214055394c710d3919b44fc7822cc9b6 \
		-a `${ECHO} Hello | ../dMagnetic -ini ../dMagnetic.ini \
			-mag minitest.mag -gfx minitest.gfx \
			-vmode high_ansi -vcols 300 -vrows 300 \
		| md5 `==84608708bfa3ff2dc4964b255766dd81 \
		-a `${ECHO} Hello | ../dMagnetic -ini ../dMagnetic.ini \
			-mag minitest.mag -gfx minitest.gfx \
			-vmode high_ansi2 -vcols 300 -vrows 300 \
		| md5 `==07c938bd0d77523d1be8e971d8610591 \
		-a `${ECHO} Hello | ../dMagnetic -ini ../dMagnetic.ini \
			-mag minitest.mag -gfx minitest.gfx \
			-vmode sixel -vcols 300 -vrows 300 \
		| md5 `==d3708a8ddf81f504b86c767648dbacb0 \
		]; \
		then ${ECHO} ok; else ${ECHO} expected output not seen; exit 1; fi

.include "../../mk/bsd.pkg.mk"
