# $NetBSD: Makefile,v 1.9 2000/11/03 00:16:36 jlam Exp $

DISTNAME=		boost_all
PKGNAME=		boost-1.18.1
WRKSRC=			${WRKDIR}/boost_1_18_1
CATEGORIES=		devel
MASTER_SITES=		http://www.boost.org/
EXTRACT_SUFX=		.zip

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.boost.org/

# Need working <limits> and <memory> not present in NetBSD yet.
DEPENDS+=		sgi-stl>=3.2:../../devel/sgi-stl

DIST_SUBDIR=		${PKGNAME}
EXTRACT_CMD=		unzip -aaoq ${DOWNLOADED_DISTFILE}

USE_LIBTOOL=		# defined
BOOST_VERS=		0:0
MAKE_ENV+=		BOOST_VERS="${BOOST_VERS}"

LIBDIR=			${PREFIX}/lib
INCDIR=			${PREFIX}/include/boost
HTMLDIR=		${PREFIX}/share/doc/html/boost

# 2-step extraction process:
#
# 1) Extract everything in text mode with CR/LF -> LF conversions.
# 2) Extract binary files in binary mode.
#
# Even though our current GCC (egcs-1.1.2) doesn't support namespaces and
# hence can't compile some of the C++ constructs used by some of the Boost
# libraries, we install all of it anyway, just in case there is an installed
# compiler (like gcc-2.95.2) capable of compiling them.
#
post-extract:
	cd ${WRKDIR} && unzip -aCoq \
		${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} "*.gif" "*.jpg" "*.zip"
	cd ${WRKSRC} && unzip -aaCqu \
		libs/pri_queue/boost-heap-1.0.zip "boost/*"

do-configure:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-build:
	${FIND} ${WRKSRC}/libs \
		\( -name "*.zip" -or -name "*.tgz" \
		   -or -name "*.orig" -or -name "*.bak" \
		   -or -name "c++boost.gif" \) \
		-exec ${RM} -f {} \;

do-install:
	cd ${WRKSRC}; ${LIBTOOL} ${INSTALL_DATA} libboost.la ${LIBDIR}
	${CP} -R ${WRKSRC}/boost ${PREFIX}/include
	${MKDIR} ${HTMLDIR}
	${INSTALL_DATA} \
		${WRKSRC}/c++boost.gif \
		${WRKSRC}/index.htm \
		${WRKSRC}/libraries.htm \
		${HTMLDIR}
	${CP} -R ${WRKSRC}/libs ${WRKSRC}/more ${HTMLDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${INCDIR} ${HTMLDIR}
	${CHMOD} -R a+r-w ${INCDIR} ${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
