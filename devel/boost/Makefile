# $NetBSD: Makefile,v 1.18 2004/04/24 22:46:09 jlam Exp $
#

DISTNAME=		boost-1.30.2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=boost/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.boost.org/
COMMENT=		Free, portable libraries that integrate with the ISO C++ Stdlib

# Need working <limits> and <memory> not present in NetBSD yet.
DEPENDS+=		sgi-stl>=3.2:../../devel/sgi-stl

USE_LIBTOOL=		# defined
BOOST_VERS=		0:0
MAKE_ENV+=		BOOST_VERS="${BOOST_VERS}"

LIBDIR=			${PREFIX}/lib
INCDIR=			${PREFIX}/include/boost
HTMLDIR=		${PREFIX}/share/doc/html/boost

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
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA} \
		${WRKSRC}/c++boost.gif \
		${WRKSRC}/index.htm \
		${HTMLDIR}
	${CP} -R ${WRKSRC}/libs ${WRKSRC}/more ${HTMLDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${INCDIR} ${HTMLDIR}
	${CHMOD} -R a+r-w ${INCDIR} ${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
