# $NetBSD: Makefile,v 1.4 2000/05/29 22:46:44 jlam Exp $

DISTNAME=		boost_all
PKGNAME=		boost-1.14.3
CATEGORIES=		devel
MASTER_SITES=		http://www.boost.org/
EXTRACT_SUFX=		.zip

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.boost.org/

# Need working <limits> and <memory> not present in NetBSD yet.
DEPENDS+=		sgi-stl>=3.2:../../devel/sgi-stl

USE_LIBTOOL=		# defined

DIST_SUBDIR=		${PKGNAME}
EXTRACT_CMD=		${LOCALBASE}/bin/unzip -aaLu ${DOWNLOADED_DISTFILE}
NO_WRKSUBDIR=		# defined

BOOST_VERS=		0:0
MAKE_ENV+=		BOOST_VERS="${BOOST_VERS}"

INCSDIR=		${PREFIX}/include
LIBDIR=			${PREFIX}/lib
HTMLDOCDIR=		${PREFIX}/share/doc/html

post-extract:
	cd ${WRKSRC}; ${LOCALBASE}/bin/unzip -aCLo \
		${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} "*.gif" "*.jpg" "*.zip"
	cd ${WRKSRC}; ${LOCALBASE}/bin/unzip -aaCLu \
		libs/pri_queue/boost-heap-1.0.zip "boost/*"

do-configure:
	cd ${FILESDIR}; ${CP} Makefile ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${INCSDIR}/boost
	${INSTALL_DATA_DIR} ${INCSDIR}/boost/detail
	cd ${WRKSRC}; \
	for file in `${GREP} "^include/" ${PLIST_SRC} \
	    | ${SED} "s,^include/,,g"`; do \
		${ECHO} ${INSTALL_DATA} $${file} ${INCSDIR}/$${file}; \
		${INSTALL_DATA} $${file} ${INCSDIR}/$${file}; \
	done
	cd ${WRKSRC}; ${LIBTOOL} ${INSTALL_DATA} libboost.la ${LIBDIR}
	${INSTALL_DATA_DIR} ${HTMLDOCDIR}/boost
	${INSTALL_DATA_DIR} ${HTMLDOCDIR}/boost/libs
	${INSTALL_DATA_DIR} ${HTMLDOCDIR}/boost/libs/array
	${INSTALL_DATA_DIR} ${HTMLDOCDIR}/boost/libs/compose
	${INSTALL_DATA_DIR} ${HTMLDOCDIR}/boost/libs/integer
	${INSTALL_DATA_DIR} ${HTMLDOCDIR}/boost/libs/min_rand
	${INSTALL_DATA_DIR} ${HTMLDOCDIR}/boost/libs/pri_queue
	${INSTALL_DATA_DIR} ${HTMLDOCDIR}/boost/libs/rational
	${INSTALL_DATA_DIR} ${HTMLDOCDIR}/boost/libs/smart_ptr
	${INSTALL_DATA_DIR} ${HTMLDOCDIR}/boost/libs/timer
	${INSTALL_DATA_DIR} ${HTMLDOCDIR}/boost/libs/utility
	${INSTALL_DATA_DIR} ${HTMLDOCDIR}/boost/more
	cd ${WRKSRC}; \
	for file in `${GREP} "^share/doc/html/boost/" ${PLIST_SRC} \
	    | ${SED} "s,^share/doc/html/boost/,,g"`; do \
		${ECHO} ${INSTALL_DATA} $${file} ${HTMLDOCDIR}/boost/$${file}; \
		${INSTALL_DATA} $${file} ${HTMLDOCDIR}/boost/$${file}; \
	done

.include "../../mk/bsd.pkg.mk"
