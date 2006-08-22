# $NetBSD: Makefile,v 1.6 2006/08/22 18:21:22 wiz Exp $
#

DISTNAME=	pkg-config-0.21
CATEGORIES=	devel
MASTER_SITES=	http://pkgconfig.freedesktop.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pkgconfig.freedesktop.org/
COMMENT=	System for managing library compile/link flags

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
CONFIGURE_ARGS+=	--disable-threads

# old name of the package
CONFLICTS=		pkgconfig-[0-9]*

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "IRIX"
# configure bails out in subdir after re-parsing the cache
CONFIGURE_ARGS+=	--cache-file=/dev/null
.endif

# needed for fifth test case
BUILDLINK_PASSTHRU_DIRS= /private-dep /public-dep /requires-test
TEST_TARGET=		check

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
