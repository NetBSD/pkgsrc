# $NetBSD: Makefile,v 1.40 2019/09/15 13:13:47 nia Exp $

DISTNAME=	expat-2.2.8
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=libexpat/}
GITHUB_PROJECT=	libexpat
GITHUB_RELEASE=	R_2_2_8

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libexpat.github.io/
COMMENT=	XML parser library written in C
LICENSE=	mit

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

# C++ is needed for tests only
#USE_LANGUAGES=		c c++
#TEST_TARGET=		check
#USE_TOOLS+=		bash
#REPLACE_BASH=		test-driver-wrapper.sh

PKGCONFIG_OVERRIDE+=	expat.pc.in

DOCDIR=	${PREFIX}/share/doc/expat

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/reference.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/style.css ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
