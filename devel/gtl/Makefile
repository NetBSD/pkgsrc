# $NetBSD: Makefile,v 1.8 2000/10/12 17:31:08 jlam Exp $

DISTNAME=		GTL-0.3.3
PKGNAME=		gtl-0.3.3
CATEGORIES=		devel
MASTER_SITES=		http://infosun.fmi.uni-passau.de/GTL/archive/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.fmi.uni-passau.de/Graphlet/GTL/

USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

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
