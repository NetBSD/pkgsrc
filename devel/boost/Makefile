# $NetBSD: Makefile,v 1.7 2000/07/13 18:25:32 jlam Exp $

DISTNAME=		boost_all
PKGNAME=		boost-1.16.1
CATEGORIES=		devel
MASTER_SITES=		http://www.boost.org/
EXTRACT_SUFX=		.zip

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.boost.org/

# Need working <limits> and <memory> not present in NetBSD yet.
DEPENDS+=		sgi-stl>=3.2:../../devel/sgi-stl

USE_LIBTOOL=		# defined

DIST_SUBDIR=		${PKGNAME}
NO_WRKSUBDIR=		# defined

BOOST_VERS=		0:0
MAKE_ENV+=		BOOST_VERS="${BOOST_VERS}"

# 2-step extraction process:
#
# 1) Extract everything in text mode with CR/LF -> LF conversions.
# 2) Extract binary files in binary mode.
#
# We remove the dir_it library since our GCC (egcs-1.1.2) doesn't
# support namespaces and hence can't compile `struct iterator' needed
# by dir_it.
#
post-extract:
	cd ${WRKSRC} && unzip -aaLo \
		${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
	cd ${WRKSRC} && unzip -aCLo \
		${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} "*.gif" "*.jpg" "*.zip"
	cd ${WRKSRC} && unzip -aaCLu \
		libs/pri_queue/boost-heap-1.0.zip "boost/*"
	${RM} -rf ${WRKSRC}/libs/dir_it

post-build:
	${FIND} ${WRKSRC}/libs \
		\( -name "*.zip" -or -name "*.tgz" \
		   -or -name "*.orig" -or -name "*.bak" \
		   -or -name "c++boost.gif" \) \
		-exec ${RM} {} \;

do-configure:
	cd ${FILESDIR}; ${CP} Makefile ${WRKSRC}

do-install:
	cd ${WRKSRC}; ${LIBTOOL} ${INSTALL_DATA} libboost.la ${LIBDIR}
	${CP} -R ${WRKSRC}/boost ${PREFIX}/include
	${MKDIR} ${PREFIX}/share/doc/html/boost
	${INSTALL_DATA} \
		${WRKSRC}/c++boost.gif \
		${WRKSRC}/index.htm \
		${WRKSRC}/libraries.htm \
		${PREFIX}/share/doc/html/boost
	${CP} -R ${WRKSRC}/libs ${WRKSRC}/more ${PREFIX}/share/doc/html/boost
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} \
		${PREFIX}/include/boost ${PREFIX}/share/doc/html/boost
	${CHMOD} -R a+r-w \
		${PREFIX}/include/boost ${PREFIX}/share/doc/html/boost

.include "../../mk/bsd.pkg.mk"
