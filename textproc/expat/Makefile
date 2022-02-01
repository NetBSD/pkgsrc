# $NetBSD: Makefile,v 1.49 2022/02/01 12:10:17 wiz Exp $

DISTNAME=	expat-2.4.4
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

CONFIGURE_ARGS+=	--without-examples
CONFIGURE_ARGS+=	--without-tests
# workaround suggested by upstream; xmlwf.1 is in tarball, so docbook not needed
CONFIGURE_ENV+=		DOCBOOK_TO_MAN=false
CONFIGURE_ARGS+=	--without-docbook

USE_LANGUAGES=	c c++
TEST_TARGET=	test
USE_TOOLS+=	bash:test
REPLACE_BASH=	test-driver-wrapper.sh
# we can't use cmake due to a cyclic dependency
#USE_CMAKE=	yes
#TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}

PKGCONFIG_OVERRIDE+=	expat.pc.in

DOCDIR=	${PREFIX}/share/doc/expat

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/reference.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/style.css ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
