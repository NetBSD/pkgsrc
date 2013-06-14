# $NetBSD: Makefile,v 1.19 2013/06/14 09:00:19 obache Exp $
#

.include "Makefile.common"

CATEGORIES=	multimedia

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.libming.org/
COMMENT=	SWF output library
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config bison flex
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--disable-php
CONFIGURE_ARGS+=	--disable-tcl

PKGCONFIG_OVERRIDE+=	src/libming.pc.in

.include "../../mk/bsd.prefs.mk"

.if defined(PKGSRC_RUN_TEST) && !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
# Test require perl
USE_TOOLS+=	perl
TEST_TARGET=	check
.endif

# XXX: "man" is not in SUBDIRS of "docs"
INSTALL_DIRS=	. docs/man

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/giflib.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
