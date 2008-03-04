# $NetBSD: Makefile,v 1.3 2008/03/04 18:12:59 jlam Exp $

DISTNAME=	fgmp-1.0b5-src-10.10
PKGNAME=	fgmp-1.0b5
CATEGORIES=	math
MASTER_SITES=	http://hpux.cs.utah.edu/hppd/cgi-bin/redirect?hpux/Maths/Misc/fgmp-1.0b5/

MAINTAINER=	pkgsrc-user@NetBSD.org
HOMEPAGE=	http://hpux.cs.utah.edu/hppd/hpux/Maths/Misc/fgmp-1.0b5/
COMMENT=	Minimalist free re-implementation of GNU multi-precision routines

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LIBTOOL=	yes
NO_CONFIGURE=	yes

INSTALLATION_DIRS=	include lib

do-build:
	cd ${WRKSRC} && (						\
		${LIBTOOL} --mode=compile ${CC} -O -c gmp.c; 		\
		${LIBTOOL} --mode=link ${CC} -o libfgmp.la gmp.lo	\
			-rpath ${PREFIX}/lib -version-info 1:0;		\
	)

do-install:
	cd ${WRKSRC} && ${LIBTOOL} --mode=install ${INSTALL_LIB} libfgmp.la \
		${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/gmp.h ${DESTDIR}${PREFIX}/include/fgmp.h

.include "../../mk/bsd.pkg.mk"
