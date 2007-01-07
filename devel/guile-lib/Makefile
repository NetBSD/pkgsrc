# $NetBSD: Makefile,v 1.11 2007/01/07 09:04:09 rillig Exp $

DISTNAME=	guile-lib-0.1.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://download.gna.org/guile-lib/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://home.gna.org/guile-lib/
COMMENT=	Library functions for Guile, implemented in Scheme

# This package may not be built from the src directory (arch configure
# rules).  The build directory must be created by hand; see the
# pre-configure target.
#
HAS_CONFIGURE=		yes
CONFIGURE_DIRS=		build
CONFIGURE_SCRIPT=	../src/configure
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--with-pkginfodir=${PKGINFODIR:Q}
OVERRIDE_GNU_CONFIG_SCRIPTS=	yes

USE_TOOLS+=	gmake makeinfo
TEXINFO_REQD=	4.2
INFO_FILES=	# PLIST
TEST_TARGET=	test

.include "../../lang/guile/buildlink3.mk"

pre-configure:
	mkdir ${WRKSRC}/build

.include "../../mk/bsd.pkg.mk"
