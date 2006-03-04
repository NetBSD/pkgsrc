# $NetBSD: Makefile,v 1.11 2006/03/04 21:30:08 jlam Exp $
#

DISTNAME=	statist-1.0.1
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://www.usf.uni-osnabrueck.de/~breiter/tools/statist/v${PKGVERSION}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.usf.uni-osnabrueck.de/~breiter/tools/statist/index.en.html
COMMENT=	Small and portable statistics program

DEPENDS+=	gnuplot-[0-9]*:../../graphics/gnuplot

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_LIBTOOL=	YES

INSTALLATION_DIRS=	bin lib

do-install:
	cd ${WRKSRC} &&							\
	${LIBTOOL} --mode=install					\
		${INSTALL_DATA} libstatist.la ${PREFIX}/lib &&		\
	${LIBTOOL} --mode=install					\
		${INSTALL_PROGRAM} statist ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/statist
	${INSTALL_DATA} ${WRKSRC}/../doc/*.ps ${PREFIX}/share/doc/statist

.include "../../mk/bsd.pkg.mk"
