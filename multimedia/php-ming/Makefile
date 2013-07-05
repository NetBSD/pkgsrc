# $NetBSD: Makefile,v 1.24 2013/07/05 13:29:41 ryoon Exp $

.include "../../multimedia/ming/Makefile.common"
PECL_VERSION=		${MING_VERSION}
MODNAME=		ming
PKGREVISION=		1
CATEGORIES+=		multimedia
DIST_SUBDIR?=		#empty
EXTRACT_SUFX=		.tar.gz

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://www.libming.org/
COMMENT=		PHP extension for Ming library
LICENSE=		php

CONFLICTS=	php-ming-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=${BUILDLINK_PREFIX.ming}
PHPSETUPSUBDIR=		php_ext
MODULESDIR=		${WRKSRC}/${PHPSETUPSUBDIR}/modules
CONFIGURE_DIRS=		${PHPSETUPSUBDIR}

# missing in 0.4.4 release tarball.
post-extract:
		${CP} ${FILESDIR}/config.m4 ${WRKSRC}/${PHPSETUPSUBDIR}

.include "../../lang/php/ext.mk"
.include "../../multimedia/ming/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
