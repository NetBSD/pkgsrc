# $NetBSD: Makefile,v 1.13 2002/07/07 10:21:38 wiz Exp $

DISTNAME=		boost_1_28_0
PKGNAME=		${DISTNAME:C/_/-/:C/_/./g}
CATEGORIES=		devel
MASTER_SITES=		http://boost.sourceforge.net/release/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.boost.org/
COMMENT=		free, portable libraries that integrate with the ISO C++ Standard Library

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
