# $NetBSD: Makefile,v 1.16 2012/05/12 11:32:39 obache Exp $

.include "../../multimedia/ming/Makefile.common"
PECL_VERSION=		${MING_VERSION}
MODNAME=		ming
CATEGORIES+=		multimedia
DIST_SUBDIR?=		#empty

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://www.libming.org/
COMMENT=		PHP extension for Ming library
LICENSE=		php

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-ming-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=${BUILDLINK_PREFIX.ming}
PHPSETUPSUBDIR=		php_ext
MODULESDIR=		${WRKSRC}/${PHPSETUPSUBDIR}/modules
CONFIGURE_DIRS=		${PHPSETUPSUBDIR}

# missing in 0.4.4 release tarball.
post-extract:
		${CP} ${FILESDIR}/config.m4 ${WRKSRC}/${PHPSETUPSUBDIR}

# to avoid downgrade version
.include "../../lang/php/phpversion.mk"
.if ${PKG_PHP_VERSION} == "5" || ${PKG_PHP_VERSION} == "52"
PECL_LEGACY_VERSION_SCHEME=	yes
.endif

.include "../../lang/php/ext.mk"
.include "../../multimedia/ming/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
