# $NetBSD: Makefile,v 1.14 2004/04/24 22:46:09 jlam Exp $

DISTNAME=		GTL-0.3.3
PKGNAME=		gtl-0.3.3
CATEGORIES=		devel
MASTER_SITES=		http://infosun.fmi.uni-passau.de/GTL/archive/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.fmi.uni-passau.de/Graphlet/GTL/
COMMENT=		C++ graph data structure library based on the STL

USE_LIBTOOL=		# defined
USE_BUILDLINK2=		# defined
USE_LANGUAGES=		c c++

LICENSE=		no-commercial-use

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		# defined
.if defined(CXXFLAGS)
CONFIGURE_ENV+=		CXXFLAGS="${CXXFLAGS}"
.endif

GTL_VERS=		0:3
MAKE_ENV+=		GTL_VERS="${GTL_VERS}"

HTMLDOCDIR=		${PREFIX}/share/doc/html/GTL

post-install:
	${INSTALL_DATA_DIR} ${HTMLDOCDIR}
	${INSTALL_DATA_DIR} ${HTMLDOCDIR}/icons
	cd ${WRKSRC}/doc/html; \
		${INSTALL_DATA} *.html ${HTMLDOCDIR}
	cd ${WRKSRC}/doc/html/icons; \
		${INSTALL_DATA} *.gif *.jpeg ${HTMLDOCDIR}/icons

.include "../../mk/bsd.pkg.mk"
