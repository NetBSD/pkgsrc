# $NetBSD: Makefile,v 1.1 2014/11/29 15:53:11 prlw1 Exp $

DISTNAME=	pmw-4.28
CATEGORIES=	print
MASTER_SITES=	http://www.quercite.com/

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://www.quercite.com/pmw.html
COMMENT=	High quality music typesetting program
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

BUILD_TARGET=	build

SPECPDF=	${PREFIX}/share/doc/pmw/spec.pdf
MESSAGE_SUBST+=	SPECPDF=${SPECPDF}
MESSAGE_SUBST+=	GS=${PREFIX}/bin/gs
MESSAGE_SUBST+=	BINDIR=${PREFIX}/bin
MESSAGE_SUBST+=	DATADIR=${PREFIX}/share/pmw
MESSAGE_SUBST+=	MANDIR=${PREFIX}/${PKGMANDIR}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/spec.pdf ${DESTDIR}${SPECPDF}

.include "../../mk/bsd.pkg.mk"
