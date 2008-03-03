# $NetBSD: Makefile,v 1.4 2008/03/03 18:25:52 jlam Exp $
#

PKGNAME=		mflteco-19920331
DISTNAME=		mflteco
CATEGORIES=		editors
MASTER_SITES=		http://www.catb.org/~esr/retro/

MAINTAINER=		is@NetBSD.org
HOMEPAGE=		http://www.catb.org/~esr/retro/
COMMENT=		MFL clone of Tape Editor and COrrector

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=		te

DOCS=			${LOCALBASE}/share/doc/mflteco
XMPL=			${LOCALBASE}/share/examples/mflteco

pre-patch:
	cp ${WRKSRC}/Makefile.sun4 ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/te ${DESTDIR}${LOCALBASE}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCS}
	${INSTALL_DATA_DIR} ${DESTDIR}${XMPL}
	${INSTALL_DATA} ${WRKSRC}/00README ${DESTDIR}${DOCS}
	${INSTALL_DATA} ${WRKSRC}/teco.doc ${DESTDIR}${DOCS}
	${INSTALL_DATA} ${WRKSRC}/teco.doc.1 ${DESTDIR}${DOCS}
	${INSTALL_DATA} ${WRKSRC}/.tecorc ${DESTDIR}${XMPL}
	${INSTALL_DATA} ${WRKSRC}/pi.tec ${DESTDIR}${XMPL}
	${INSTALL_DATA} ${WRKSRC}/sample_tecorc.old ${DESTDIR}${XMPL}
	${INSTALL_DATA} ${WRKSRC}/tecorc.mch ${DESTDIR}${XMPL}

.include "../../mk/bsd.pkg.mk"
