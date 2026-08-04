# $NetBSD: Makefile,v 1.24 2026/08/04 20:28:49 wiz Exp $

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

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
