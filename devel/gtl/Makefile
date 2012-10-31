# $NetBSD: Makefile,v 1.30 2012/10/31 11:17:04 asau Exp $

DISTNAME=		GTL-1.2.4-lgpl
PKGNAME=		${DISTNAME:S/-lgpl//:tl}
CATEGORIES=		devel
MASTER_SITES=		http://www.fim.uni-passau.de/fileadmin/files/lehrstuhl/brandenburg/projekte/gtl/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.infosun.fim.uni-passau.de/GTL/
COMMENT=		C++ graph data structure library based on the STL
LICENSE=		gnu-lgpl-v3

USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++

# previous version of the same
CONFLICTS=		gtl0-[0-9]*

GNU_CONFIGURE=		yes

WRKSRC=		${WRKDIR}/${DISTNAME:S/-lgpl//}

DOCDIR=		${PREFIX}/share/doc/GTL

# tests/test.gml is missing in archive
#TEST_TARGET=	runtests

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}/icons
	cd ${WRKSRC}/doc; \
		${INSTALL_DATA} *.html style.css ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/icons/*.jpeg ${DESTDIR}${DOCDIR}/icons
	${INSTALL_DATA} ${WRKSRC}/doc/userguide/GTL.ps ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
