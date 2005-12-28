# $NetBSD: Makefile,v 1.1.1.1 2005/12/28 22:29:17 is Exp $
#

PKGNAME=		mflteco-19920331
DISTNAME=		mflteco
CATEGORIES=		editors
MASTER_SITES=		http://www.catb.org/~esr/retro/

MAINTAINER=		is@netbsd.org
HOMEPAGE=		http://www.catb.org/~esr/retro/
COMMENT=		MFL clone of Tape Editor and COrrector

BUILD_TARGET=		te

DOCS=			${LOCALBASE}/share/doc/mflteco
XMPL=			${LOCALBASE}/share/examples/mflteco

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/te ${LOCALBASE}/bin
	${INSTALL_DATA_DIR} ${DOCS}
	${INSTALL_DATA_DIR} ${XMPL}
	${INSTALL_DATA} ${WRKSRC}/00README ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/teco.doc ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/teco.doc.1 ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/.tecorc ${XMPL}
	${INSTALL_DATA} ${WRKSRC}/pi.tec ${XMPL}
	${INSTALL_DATA} ${WRKSRC}/sample_tecorc.old ${XMPL}
	${INSTALL_DATA} ${WRKSRC}/tecorc.mch ${XMPL}


pre-patch: 
	cp ${WRKSRC}/Makefile.sun4 ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
