# $NetBSD: Makefile,v 1.1.1.1 2007/01/03 07:53:37 agc Exp $

DISTNAME=	fgmp-1.0b5-src-10.10
PKGNAME=	fgmp-1.0b5
CATEGORIES=	math
MASTER_SITES=	http://hpux.cs.utah.edu/hppd/cgi-bin/redirect?hpux/Maths/Misc/fgmp-1.0b5/

MAINTAINER=	pkgsrc-user@NetBSD.org
HOMEPAGE=	http://hpux.cs.utah.edu/hppd/hpux/Maths/Misc/fgmp-1.0b5/
COMMENT=	Minimalist free re-implementation of GNU multi-precision routines

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LIBTOOL=	yes

do-configure:;

do-build:
	cd ${WRKSRC} && (						\
		${LIBTOOL} --mode=compile ${CC} -O -c gmp.c; 		\
		${LIBTOOL} --mode=link ${CC} -o libfgmp.la gmp.lo	\
			-rpath ${PREFIX}/lib -version-info 1:0;		\
	)

do-install:
	cd ${WRKSRC} && ${LIBTOOL} --mode=install ${INSTALL_LIB} libfgmp.la ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/gmp.h ${PREFIX}/include/fgmp.h

.include "../../mk/bsd.pkg.mk"
