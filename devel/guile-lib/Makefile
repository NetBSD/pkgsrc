# $NetBSD: Makefile,v 1.1.1.1 2004/12/03 16:50:22 wiz Exp $

DISTNAME=	guile-lib-0.1.2
CATEGORIES=	devel
MASTER_SITES=	http://download.gna.org/guile-lib/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://home.gna.org/guile-lib/
COMMENT=	Library functions for Guile, implemented in Scheme

# This package may not be built from the src directory (arch configure
# rules).  The build directory must be created by hand; see the
# pre-configure target.
HAS_CONFIGURE=	yes
CONFIGURE_DIRS=	${WRKSRC}/build
BUILD_DIRS=	${WRKSRC}/build
CONFIGURE_SCRIPT=	../src/configure
CONFIGURE_ARGS=	--prefix=${PREFIX}

USE_BUILDLINK3=	YES
USE_GNU_TOOLS=	make
USE_MAKEINFO=	yes
INFO_FILES=	guile-library.info
TEST_TARGET=	test

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
