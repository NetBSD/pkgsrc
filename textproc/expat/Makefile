# $NetBSD: Makefile,v 1.43 2020/10/07 19:53:02 wiz Exp $

DISTNAME=	expat-2.2.10
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=libexpat/}
GITHUB_PROJECT=	libexpat
GITHUB_RELEASE=	R_${PKGVERSION_NOREV:S/./_/g}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libexpat.github.io/
COMMENT=	XML parser library written in C
LICENSE=	mit

USE_CMAKE=	yes

USE_LANGUAGES=		c c++
TEST_TARGET=		test
USE_TOOLS+=		bash:test
REPLACE_BASH=		test-driver-wrapper.sh
TEST_ENV+=		LD_LIBRARY_PATH=${WRKSRC}

PKGCONFIG_OVERRIDE+=	expat.pc.in

DOCDIR=	${PREFIX}/share/doc/expat

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/reference.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/style.css ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
