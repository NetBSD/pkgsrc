# $NetBSD: Makefile,v 1.33.8.1 2017/06/21 18:36:19 bsiegert Exp $
#

DISTNAME=	expat-2.2.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=expat/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://expat.sourceforge.net/
COMMENT=	XML parser library written in C
LICENSE=	mit

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

# C++ is needed for tests only
#USE_LANGUAGES=		c c++
#TEST_TARGET=		check

PKGCONFIG_OVERRIDE+=	expat.pc.in

DOCDIR=	${PREFIX}/share/doc/html/expat

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/reference.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/style.css ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
