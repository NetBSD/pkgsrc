# $NetBSD: Makefile,v 1.15 2004/01/27 00:53:12 heinz Exp $

DISTNAME=	STLport-4.6
PKGNAME=	stlport-4.6
CATEGORIES=	devel
MASTER_SITES=	http://www.stlport.com/archive/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.stlport.org/
COMMENT=	Complete C++ standard library

USE_BUILDLINK2=	# defined
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	# defined
USE_GCC_SHLIB=	# defined

NO_CONFIGURE=	# defined
BUILD_DIRS=	${WRKSRC}/src

MAKE_ENV+=	CXXFLAGS="${CXXFLAGS}"
MAKEFILE=	gcc-libtool.mak

PTHREAD_OPTS+=	require

INCDIR=		${PREFIX}/include/stlport
LIBDIR=		${PREFIX}/lib
HTMLDIR=	${PREFIX}/share/doc/html/stlport

pre-install:
	cd ${WRKSRC}/stlport && ${RM} -rf BC50 config/new_compiler old_hp
	${FIND} ${WRKSRC}/stlport -name "*.orig" -print | ${XARGS} ${RM} -f

do-install:
	cd ${WRKSRC} && ${PAX} -rw stlport ${PREFIX}/include
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${INCDIR}
	${CHMOD} -R ${SHAREMODE} ${INCDIR}
	${CHMOD} -R a+X ${INCDIR}
	for lib in							\
		libstlport_gcc.la					\
		libstlport_gcc_stldebug.la;				\
	do								\
		${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/lib/$${lib} ${LIBDIR}; \
	done
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}/images
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.css *.html ${HTMLDIR}
	cd ${WRKSRC}/doc; ${INSTALL_DATA} images/* ${HTMLDIR}/images

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
