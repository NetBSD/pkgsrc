# $NetBSD: Makefile,v 1.16 2012/09/11 23:04:34 asau Exp $
#

DISTNAME=	statist-1.0.1
PKGREVISION=	3
CATEGORIES=	math
MASTER_SITES=	http://www.usf.uni-osnabrueck.de/~breiter/tools/statist/v${PKGVERSION}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.usf.uni-osnabrueck.de/~breiter/tools/statist/index.en.html
COMMENT=	Small and portable statistics program
LICENSE=	gnu-gpl-v2

DEPENDS+=	gnuplot-[0-9]*:../../graphics/gnuplot
CONFLICTS=	freeze-[0-9]* # bin/statist

MAKE_JOBS_SAFE=		no

CONFIGURE_DIRS=	src
BUILD_DIRS=	src

USE_LIBTOOL=	YES

AUTO_MKDIRS=	yes

do-install:
	cd ${WRKSRC}/src &&							\
	${LIBTOOL} --tag=CC --mode=install					\
		${INSTALL_DATA} libstatist.la ${DESTDIR}${PREFIX}/lib &&\
	${LIBTOOL} --tag=CC --mode=install					\
		${INSTALL_PROGRAM} statist ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/*.ps				\
		${DESTDIR}${PREFIX}/share/doc/statist

.include "../../mk/bsd.pkg.mk"
