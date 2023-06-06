# $NetBSD: Makefile,v 1.10 2023/06/06 12:41:09 riastradh Exp $

MODNAME=	pthreads
PECL_VERSION=	2.0.10
CATEGORIES+=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/krakjoe/pthreads
COMMENT=	PHP extension for POSIX threads support
LICENSE=	php

TOOL_DEPENDS+=	re2c>=0.13.0.4:../../devel/re2c

PHP_VERSIONS_ACCEPTED=	56

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

USE_LANGUAGES+=	c c++
USE_TOOLS+=	gsed
USE_LIBTOOL=	yes

.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/php/ext.mk"
.if empty(PKG_BUILD_OPTIONS.php:Mmaintainer-zts)
BROKEN=		"Requires the maintainer-zts option enabled in PHP."
.endif
.include "../../mk/bsd.pkg.mk"
