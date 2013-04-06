# $NetBSD: Makefile,v 1.20 2013/04/06 13:02:33 rodent Exp $

.include "../../multimedia/ming/Makefile.common"
PKGREVISION=		1
PECL_VERSION=		${MING_VERSION}
MODNAME=		ming
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
