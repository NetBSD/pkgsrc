# $NetBSD: Makefile,v 1.32 2020/06/05 12:49:13 jperkin Exp $

PKGREVISION= 1
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

CONFLICTS=	php-ming-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=${BUILDLINK_PREFIX.ming}
PHPSETUPSUBDIR=		php_ext
MODULESDIR=		${WRKSRC}/${PHPSETUPSUBDIR}/modules
CONFIGURE_DIRS=		${PHPSETUPSUBDIR}
USE_TOOLS+=		aclocal autoconf automake autoheader pkg-config

# missing in 0.4.4 release tarball.
post-extract:
	${CP} ${FILESDIR}/config.m4 ${WRKSRC}/${PHPSETUPSUBDIR}

pre-configure:
	cd ${WRKSRC}; sh ./autogen.sh


.include "../../lang/php/ext.mk"
DISTNAME=		ming-${MING_VERSION:S/./_/g}
.include "../../multimedia/ming/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
