# $NetBSD: Makefile,v 1.18 2023/12/22 19:25:13 zafer Exp $
#

DISTNAME=	statist-1.0.1
PKGREVISION=	3
CATEGORIES=	math
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.usf.uni-osnabrueck.de/~breiter/tools/statist/index.en.html
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
