# $NetBSD: Makefile,v 1.6 2012/10/03 11:43:37 asau Exp $
#

PKGNAME=		mflteco-19920331
DISTNAME=		mflteco
CATEGORIES=		editors
MASTER_SITES=		http://www.catb.org/~esr/retro/

MAINTAINER=		is@NetBSD.org
HOMEPAGE=		http://www.catb.org/~esr/retro/
COMMENT=		MFL clone of Tape Editor and COrrector

BUILD_TARGET=		te

INSTALLATION_DIRS=	bin share/doc/mflteco share/examples/mflteco

pre-patch:
	cp ${WRKSRC}/Makefile.sun4 ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/te ${DESTDIR}${PREFIX}/bin
.for f in 00README teco.doc teco.doc.1
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/doc/mflteco
.endfor
.for f in .tecorc pi.tec sample_tecorc.old tecorc.mch
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/examples/mflteco
.endfor

.include "../../mk/bsd.pkg.mk"
