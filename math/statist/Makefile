# $NetBSD: Makefile,v 1.19 2026/08/04 20:29:08 wiz Exp $
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

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
