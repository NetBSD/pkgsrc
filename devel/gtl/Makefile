# $NetBSD: Makefile,v 1.5 2000/07/19 18:06:03 jlam Exp $

DISTNAME=		GTL-0.3.3
PKGNAME=		gtl-0.3.3
CATEGORIES=		devel
MASTER_SITES=		http://infosun.fmi.uni-passau.de/GTL/archive/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.fmi.uni-passau.de/Graphlet/GTL/

DEPENDS+=		sgi-stl>=3.2:../../devel/sgi-stl

GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
CPPFLAGS+=		-I${LOCALBASE}/include/sgi-stl

GTL_VERS=		0:3
MAKE_ENV+=		GTL_VERS="${GTL_VERS}"

MESSAGE_FILE=		${WRKDIR}/MESSAGE
HTMLDOCDIR=		${PREFIX}/share/doc/html/GTL

post-build:
	${SED}	-e "s,@LOCALBASE@,${LOCALBASE},g" \
		< ${PKGDIR}/MESSAGE > ${MESSAGE_FILE}

post-install:
	${INSTALL_DATA_DIR} ${HTMLDOCDIR}
	${INSTALL_DATA_DIR} ${HTMLDOCDIR}/icons
	cd ${WRKSRC}/doc/html; \
		${INSTALL_DATA} *.html ${HTMLDOCDIR}
	cd ${WRKSRC}/doc/html/icons; \
		${INSTALL_DATA} *.gif *.jpeg ${HTMLDOCDIR}/icons

.include "../../mk/bsd.pkg.mk"
