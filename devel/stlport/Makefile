# $NetBSD: Makefile,v 1.1.1.1 2000/12/27 17:37:50 jlam Exp $

DISTNAME=	STLport-4.0
PKGNAME=	stlport-4.0
CATEGORIES=	devel
MASTER_SITES=	http://www.stlport.com/archive/

MAINTAINER=	p99dreyf@criens.u-psud.fr
HOMEPAGE=	http://www.stlport.org

DEPENDS+=	gcc>=${GCC_VERS}:../../lang/gcc

USE_GMAKE=	# defined
USE_LIBTOOL=	# defined

GCC_VERS=	2.95.2
GCC_BINDIR=	${PREFIX}/gcc-${GCC_VERS}/bin

NO_CONFIGURE=	# defined

MAKE_ENV+=	CC="${GCC_BINDIR}/gcc"
MAKE_ENV+=	CPP="${GCC_BINDIR}/cpp"
MAKE_ENV+=	CXX="${GCC_BINDIR}/c++"
MAKE_ENV+=	CPPFLAGS="${CPPFLAGS}"
MAKE_ENV+=	CXXFLAGS="${CXXFLAGS}"
MAKEFILE=	gcc-libtool.mak

# A threads implementation isn't necessary when building the library.
CPPFLAGS+=	-D__STL_NO_THREADS

INCDIR=		${PREFIX}/include/stlport
LIBDIR=		${PREFIX}/lib
HTMLDIR=	${PREFIX}/share/doc/html/stlport

do-build:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${ALL_TARGET}

pre-install:
	cd ${WRKSRC}/stlport && ${RM} -rf BC50 SC5 config/new_compiler old_hp
	${FIND} ${WRKSRC}/stlport -name "*.orig" -exec ${RM} -f {} \;

do-install:
	cd ${WRKSRC} && ${PAX} -rw stlport ${PREFIX}/include
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${INCDIR}
	${CHMOD} -R ${SHAREMODE} ${INCDIR}
	${CHMOD} -R a+X ${INCDIR}
	for lib in \
		libstlport_gcc.la \
		libstlport_gcc_debug.la \
		libstlport_gcc_stldebug.la; \
	do \
		${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/lib/$${lib} ${LIBDIR}; \
	done
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}/images
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.css *.html ${HTMLDIR}
	cd ${WRKSRC}/doc; ${INSTALL_DATA} images/* ${HTMLDIR}/images

.include "../../mk/bsd.pkg.mk"
