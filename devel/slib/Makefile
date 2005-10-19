# $NetBSD: Makefile,v 1.22 2005/10/19 12:38:16 adam Exp $

DISTNAME=	slib3a2
#
# Convert the version number as follows 2d2 -> 2.4.2, where the d is
# changed to a 4, representing the 4th letter.
# Thus, 3a1 -> 3.1.1
#
PKGNAME=	slib-3.1.2
CATEGORIES=	devel
MASTER_SITES=	http://swissnet.ai.mit.edu/ftpdir/scm/ \
		${MASTER_SITE_GNU:=jacal/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://swissnet.ai.mit.edu/~jaffer/SLIB.html
COMMENT=	Portable Scheme library of compatibility and utility functions

WRKSRC=		${WRKDIR}/slib
NO_CONFIGURE=	yes
NO_BUILD=	yes

SLIBDIR=	${PREFIX}/share/slib
DOCDIR=		${PREFIX}/share/doc/slib

INFO_FILES=	slib.info

INSTALLATION_DIRS=	${INFO_DIR}

do-install:
	${INSTALL_DATA_DIR} ${SLIBDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} *.scm *.init ${SLIBDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} README FAQ ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/slib.info ${PREFIX}/${INFO_DIR}

.include "../../mk/bsd.pkg.mk"
