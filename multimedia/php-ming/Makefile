# $NetBSD: Makefile,v 1.35 2023/01/29 21:17:21 ryoon Exp $

PKGREVISION= 2
.include "../../multimedia/ming/Makefile.common"
PECL_VERSION=		${MING_VERSION}
MODNAME=		ming
CATEGORIES+=		multimedia
DIST_SUBDIR?=		#empty
EXTRACT_SUFX=		.tar.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.libming.org/
COMMENT=		PHP extension for Ming library
LICENSE=		php

PHP_VERSIONS_ACCEPTED=	56 74

CONFLICTS=	php-ming-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=${BUILDLINK_PREFIX.ming}
CONFIGURE_ARGS+=	MING_DIR=${PREFIX}
PHPSETUPSUBDIR=		php_ext
MODULESDIR=		${WRKSRC}/${PHPSETUPSUBDIR}/modules
CONFIGURE_DIRS=		${PHPSETUPSUBDIR}
USE_TOOLS+=		aclocal autoconf automake autoheader pkg-config

pre-configure:
	cd ${WRKSRC}; sh ./autogen.sh


.include "../../lang/php/ext.mk"
DISTNAME=		ming-${MING_VERSION:S/./_/g}
.include "../../multimedia/ming/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
