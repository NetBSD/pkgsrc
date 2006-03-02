# $NetBSD: Makefile,v 1.15 2006/03/02 19:19:43 drochner Exp $
#

DISTNAME=	metakit-2.4.9.5
PKGNAME=	metakit-lib-2.4.9.5
CATEGORIES=	databases
MASTER_SITES=	http://www.equi4.com/pub/mk/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.equi4.com/metakit/
COMMENT=	Embedded database library

GNU_CONFIGURE=	yes
CONFIGURE_DIRS=	builds
CONFIGURE_SCRIPT= ../unix/configure
CONFIGURE_ARGS+=	--without-tcl
BUILD_DIRS=	builds
USE_LANGUAGES=	c++
USE_LIBTOOL=	yes
TEST_TARGET=	test

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/mk4io.h ${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
