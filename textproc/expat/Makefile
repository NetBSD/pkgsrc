# $NetBSD: Makefile,v 1.42 2020/03/26 11:57:10 nia Exp $

DISTNAME=	expat-2.2.9
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=libexpat/}
GITHUB_PROJECT=	libexpat
GITHUB_RELEASE=	R_${PKGVERSION_NOREV:S/./_/g}

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

CONFIGURE_ARGS+=	--without-examples
CONFIGURE_ARGS+=	--without-tests
CONFIGURE_ARGS+=	--without-docbook

PKGCONFIG_OVERRIDE+=	expat.pc.in

DOCDIR=	${PREFIX}/share/doc/expat

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/reference.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/style.css ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
