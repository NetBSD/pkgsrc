# $NetBSD: Makefile,v 1.3 2003/07/17 21:48:11 grant Exp $
#

DISTNAME=	statist-1.0.1
WRKSRC=		${WRKDIR}/${DISTNAME}/src
CATEGORIES=	math
MASTER_SITES=	http://www.usf.uni-osnabrueck.de/~breiter/tools/statist/v${PKGVERSION}/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.usf.uni-osnabrueck.de/~breiter/tools/statist/index.en.html
COMMENT=	small and portable statistics program

DEPENDS+=	gnuplot-[0-9]*:../../graphics/gnuplot

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES

do-install:
	cd ${WRKSRC} &&							\
	${LIBTOOL} --mode=install					\
		${INSTALL_DATA} libstatist.la ${PREFIX}/lib &&		\
	${LIBTOOL} --mode=install					\
		${INSTALL_PROGRAM} statist ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/statist
	${INSTALL_DATA} ${WRKSRC}/../doc/*.ps ${PREFIX}/share/doc/statist

.include "../../mk/bsd.pkg.mk"
