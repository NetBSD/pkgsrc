# $NetBSD: Makefile,v 1.1.1.1 2000/08/25 16:03:42 mjl Exp $
#

DISTNAME=	pwlib_min_1.1pl17
PKGNAME=	pwlib-1.1pl17
CATEGORIES=	devel
MASTER_SITES=	http://www.openh323.org/bin/ \
		http://www.au.openh323.org/bin/ \
		http://www.au2.openh323.org/bin/ \
		http://www.us1.openh323.org/bin/ \
		http://www.us2.openh323.org/bin/ \
		http://www.ru.openh323.org/bin/ \
		http://www.de.openh323.org/bin/ \
		http://www.at.openh323.org/bin/ \
		http://www.cz.openh323.org/bin/ \
		http://www.pl.openh323.org/bin/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.openh323.org/

DEPENDS+=	unproven-pthreads:../../devel/unproven-pthreads

WRKSRC=		${WRKDIR}/pwlib

USE_GMAKE=	yes
USE_LIBTOOL=	yes

pre-build:
		-cd ${WRKSRC}; ${LN} -f -s .. share

do-build:
		cd ${WRKSRC}; env PWLIBDIR=`pwd` ${GMAKE} opt

do-install:
		cd ${WRKSRC}; env PWLIBDIR=`pwd` ${GMAKE} install;
		${MKDIR} ${PREFIX}/include/ptclib ${PREFIX}/include/ptlib/unix/ptlib
		cd ${WRKSRC}/include; for f in `find . -name CVS -prune -o -type f -print` ; \
			do ${BSD_INSTALL_DATA} $$f ${PREFIX}/include/`dirname $$f`; done
		${MKDIR} ${PREFIX}/share/pwlib/make
		cd ${WRKSRC}/make; for f in unix.mak common.mak lib.mak ptlib.mak ; \
			do ${BSD_INSTALL_DATA} $$f ${PREFIX}/share/pwlib/make; done

.include "../../mk/bsd.pkg.mk"
