# $NetBSD: Makefile,v 1.4 2001/02/16 14:39:03 wiz Exp $

DISTNAME=	slib2c8
PKGNAME=	slib-2c8
CATEGORIES=	devel
MASTER_SITES=	http://swissnet.ai.mit.edu/ftpdir/scm/ \
		${MASTER_SITE_GNU:=jacal/}
EXTRACT_SUFX=	.zip

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://swissnet.ai.mit.edu/~jaffer/SLIB.html
COMMENT=	portable Scheme library of compatibility and utility functions

NO_CONFIGURE=	# defined
NO_BUILD=	# defined
WRKSRC=		${WRKDIR}/slib

SLIBDIR=	${PREFIX}/share/slib
DOCDIR=		${PREFIX}/share/doc/slib

INFO_FILES=	slib.info

do-install:
	${INSTALL_DATA_DIR} ${SLIBDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} *.scm *.init ${SLIBDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} README FAQ ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/slib.info ${PREFIX}/info

.include "../../mk/bsd.pkg.mk"
