# $NetBSD: Makefile,v 1.1.1.1 2000/05/10 04:31:17 jlam Exp $

DISTNAME=		GTL-0.3.3
PKGNAME=		gtl-0.3.3
CATEGORIES=		devel
MASTER_SITES=		http://infosun.fmi.uni-passau.de/GTL/archive/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.fmi.uni-passau.de/Graphlet/GTL/

GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

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
