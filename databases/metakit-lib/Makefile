# $NetBSD: Makefile,v 1.23 2026/01/10 07:42:25 wiz Exp $

VERSION=	2.4.9.7
DISTNAME=	metakit-${VERSION}
PKGNAME=	metakit-lib-${VERSION}
CATEGORIES=	databases
MASTER_SITES=	https://www.equi4.com/pub/mk/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.equi4.com/metakit/
COMMENT=	Embedded database library

GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		builds
CONFIGURE_SCRIPT=	../unix/configure
CONFIGURE_ARGS+=	--without-tcl
BUILD_DIRS=		builds
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
TEST_TARGET=		test

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/mk4io.h ${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
