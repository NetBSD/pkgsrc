# $NetBSD: Makefile,v 1.24 2006/07/18 23:27:14 jlam Exp $

DISTNAME=		GTL-1.2.1
PKGNAME=		gtl-1.2.1
CATEGORIES=		devel
MASTER_SITES=		http://infosun.fmi.uni-passau.de/GTL/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.fmi.uni-passau.de/Graphlet/GTL/
COMMENT=		C++ graph data structure library based on the STL

USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++

# previous version of the same
CONFLICTS=		gtl0-[0-9]*

LICENSE=		no-commercial-use

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		CXXFLAGS=${CXXFLAGS:M*:Q}

DOCDIR=		${PREFIX}/share/doc/GTL

INTERACTIVE_STAGE=	fetch

FETCH_MESSAGE=								\
	"Follow the instructions at:"					\
	"    http://www.infosun.fmi.uni-passau.de/GTL/register.html"	\
	"to download the distfile."

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}/icons
	cd ${WRKSRC}/doc; \
		${INSTALL_DATA} *.html style.css ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/icons/*.jpeg ${DOCDIR}/icons
	${INSTALL_DATA} ${WRKSRC}/doc/userguide/GTL.ps ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
