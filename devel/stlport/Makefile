# $NetBSD: Makefile,v 1.30 2006/09/09 02:41:58 obache Exp $

DISTNAME=	STLport-4.6
PKGNAME=	stlport-4.6
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.stlport.com/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.stlport.org/
COMMENT=	Complete C++ standard library

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

NO_CONFIGURE=	yes
BUILD_DIRS=	src

MAKE_ENV+=	CXXFLAGS=${CXXFLAGS:M*:Q}
MAKE_FILE=	gcc-libtool.mak

PTHREAD_OPTS+=		require
PTHREAD_AUTO_VARS=	yes
LDFLAGS+=		${PTHREAD_LIBS}

LIBDIR=		${PREFIX}/lib
HTMLDIR=	${PREFIX}/share/doc/html/stlport

INSTALLATION_DIRS=	include lib

pre-install:
	cd ${WRKSRC:Q}/stlport && ${RM} -rf BC50 config/new_compiler old_hp

do-install:
	set -e;								\
	cd ${WRKSRC:Q};							\
	${FIND} stlport -type d -print					\
	| while read d; do						\
	${INSTALL_DATA_DIR} ${PREFIX:Q}/include/"$$d";			\
	done;								\
	${FIND} stlport -type f ! -name "*.orig" -print			\
	| while read f; do						\
	${INSTALL_DATA} "$$f" ${PREFIX:Q}/include/"$$f";		\
	done
	set -e;								\
	for lib in							\
		libstlport_gcc.la					\
		libstlport_gcc_stldebug.la;				\
	do								\
		${LIBTOOL} ${INSTALL_LIB} ${WRKSRC:Q}/lib/"$$lib" ${LIBDIR:Q}; \
	done
	${INSTALL_DATA_DIR} ${HTMLDIR:Q}
	${INSTALL_DATA_DIR} ${HTMLDIR:Q}/images
	cd ${WRKSRC:Q}/doc && ${INSTALL_DATA} *.css *.html ${HTMLDIR:Q}
	cd ${WRKSRC:Q}/doc && ${INSTALL_DATA} images/* ${HTMLDIR:Q}/images

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
