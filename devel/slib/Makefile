# $NetBSD: Makefile,v 1.14 2003/09/16 18:51:31 xtraeme Exp $

DISTNAME=	slib2d6
#
# Convert the version number as follows 2d2 -> 2.4.2, where the d is
# changed to a 4, representing the 4th letter.
#
PKGNAME=	slib-2.4.6
WRKSRC=		${WRKDIR}/slib
CATEGORIES=	devel
MASTER_SITES=	http://swissnet.ai.mit.edu/ftpdir/scm/ \
		${MASTER_SITE_GNU:=jacal/}
EXTRACT_SUFX=	.zip

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://swissnet.ai.mit.edu/~jaffer/SLIB.html
COMMENT=	Portable Scheme library of compatibility and utility functions

USE_BUILDLINK2=	# defined
NO_BUILD=	# defined

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
