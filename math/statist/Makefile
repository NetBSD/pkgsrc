# $NetBSD: Makefile,v 1.6 2004/04/24 04:20:12 snj Exp $
#

DISTNAME=	statist-1.0.1
CATEGORIES=	math
MASTER_SITES=	http://www.usf.uni-osnabrueck.de/~breiter/tools/statist/v${PKGVERSION}/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.usf.uni-osnabrueck.de/~breiter/tools/statist/index.en.html
COMMENT=	Small and portable statistics program

DEPENDS+=	gnuplot-[0-9]*:../../graphics/gnuplot

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_BUILDLINK3=	YES
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
