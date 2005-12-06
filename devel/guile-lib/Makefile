# $NetBSD: Makefile,v 1.7 2005/12/06 14:14:24 joerg Exp $

DISTNAME=	guile-lib-0.1.2
CATEGORIES=	devel
MASTER_SITES=	http://download.gna.org/guile-lib/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://home.gna.org/guile-lib/
COMMENT=	Library functions for Guile, implemented in Scheme

# This package may not be built from the src directory (arch configure
# rules).  The build directory must be created by hand; see the
# pre-configure target.
HAS_CONFIGURE=	yes
CONFIGURE_DIRS=	${WRKSRC}/build
BUILD_DIRS=	${WRKSRC}/build
CONFIGURE_SCRIPT=	../src/configure
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

USE_TOOLS+=	gmake
USE_MAKEINFO=	yes
TEXINFO_REQD=	4.2
INFO_FILES=	guile-library.info
TEST_TARGET=	test

pre-configure:
	${MKDIR} ${WRKSRC}/build
	${RM} ${WRKSRC}/src/build-tools/gnu/config.guess
	${LN} -s ${PKGSRCDIR}/mk/gnu-config/config.guess ${WRKSRC}/src/build-tools/gnu/config.guess
	${RM} ${WRKSRC}/src/build-tools/gnu/config.sub
	${LN} -s ${PKGSRCDIR}/mk/gnu-config/config.sub ${WRKSRC}/src/build-tools/gnu/config.sub

.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
