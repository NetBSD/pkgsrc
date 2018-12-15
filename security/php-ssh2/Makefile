# $NetBSD: Makefile,v 1.10 2018/12/15 21:12:22 wiz Exp $
#

MODNAME=		ssh2
PECL_VERSION=		1.1.2
CATEGORIES+=		security

MAINTAINER=		fhajny@NetBSD.org
HOMEPAGE=		https://www.libssh2.org/
COMMENT=		PHP bindings to the functions of libssh2
LICENSE=		php

CONFLICTS=      ${PHP_PKG_PREFIX}-${MODNAME}<1.0

PHP_VERSIONS_ACCEPTED=	70 71 72

CONFIGURE_ARGS+=	--with-ssh2=${PREFIX}

.include "../../security/libssh2/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
