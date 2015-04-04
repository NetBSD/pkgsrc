# $NetBSD: Makefile,v 1.3 2015/04/04 13:09:54 rodent Exp $

MODNAME=	pthreads
PECL_VERSION=	2.0.10
CATEGORIES+=	devel

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/krakjoe/pthreads
COMMENT=	PHP extension for POSIX threads support
LICENSE=	php

BUILD_DEPENDS+=	re2c>=0.13.0.4:../../devel/re2c

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

USE_LANGUAGES+=	c c++
USE_TOOLS+=	gsed
USE_LIBTOOL=	yes

.include "../../lang/php/phpversion.mk"

.if empty(PKG_OPTIONS.${PHP_PKG_PREFIX}:Mmaintainer-zts)
BROKEN=		Requires the maintainer-zts option enabled in PHP.
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
