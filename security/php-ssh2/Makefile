# $NetBSD: Makefile,v 1.13 2019/12/16 16:30:14 taca Exp $
#

MODNAME=		ssh2
PECL_VERSION=		1.1.2
CATEGORIES+=		security

MAINTAINER=		fhajny@NetBSD.org
HOMEPAGE=		https://www.libssh2.org/
COMMENT=		PHP bindings to the functions of libssh2
LICENSE=		php

CONFLICTS=	${PHP_PKG_PREFIX}-${MODNAME}<1.0

PHP_VERSIONS_ACCEPTED=	72

CONFIGURE_ARGS+=	--with-ssh2=${PREFIX}

.include "../../security/libssh2/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
