# $NetBSD: Makefile,v 1.17 2004/11/02 20:36:50 wiz Exp $

DISTNAME=		GTL-1.2.0
PKGNAME=		gtl-1.2.0
CATEGORIES=		devel
MASTER_SITES=		http://infosun.fmi.uni-passau.de/GTL/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.fmi.uni-passau.de/Graphlet/GTL/
COMMENT=		C++ graph data structure library based on the STL

USE_LIBTOOL=		# defined
USE_BUILDLINK3=		yes
USE_LANGUAGES=		c c++

# previous version of the same
CONFLICTS=		gtl0-[0-9]*

LICENSE=		no-commercial-use

GNU_CONFIGURE=		# defined
CONFIGURE_ENV+=		CXXFLAGS="${CXXFLAGS}"

DOCDIR=		${PREFIX}/share/doc/GTL

_FETCH_MESSAGE= \
	${ECHO} "======================================================================"; \
	${ECHO} ; \
	${ECHO} " Follow the instructions at"; \
	${ECHO} "	http://www.infosun.fmi.uni-passau.de/GTL/register.html"; \
	${ECHO} " to download the distfile."; \
	${ECHO} ; \
	${ECHO} "======================================================================"

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}/icons
	cd ${WRKSRC}/doc; \
		${INSTALL_DATA} *.html style.css ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/icons/*.jpeg ${DOCDIR}/icons
	${INSTALL_DATA} ${WRKSRC}/doc/userguide/GTL.ps ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
