# $NetBSD: Makefile,v 1.4 2018/09/17 15:15:21 prlw1 Exp $

DISTNAME=	pmw-4.30
CATEGORIES=	print
MASTER_SITES=	http://people.ds.cam.ac.uk/ph10/

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://people.ds.cam.ac.uk/ph10/pmw.html
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
