# $NetBSD: Makefile,v 1.26 2005/04/21 08:22:32 xtraeme Exp $
#

DISTNAME=	pkgconfig-0.17.2
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.freedesktop.org/software/pkgconfig/releases/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/Software/pkgconfig
COMMENT=	System for managing library compile/link flags

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
CONFIGURE_ARGS+=	--disable-threads

.include "../../mk/bsd.prefs.mk"

# without indirect-deps, it would rely on inter-library dependencies
#  which we are not ready for
CONFIGURE_ARGS+= 	--enable-indirect-deps

.if ${OPSYS} == "IRIX"
# configure bails out in subdir after re-parsing the cache
CONFIGURE_ARGS+=	--cache-file=/dev/null
.endif

TEST_TARGET=		check

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/pkgconfig

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
