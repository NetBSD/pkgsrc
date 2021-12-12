# $NetBSD: Makefile,v 1.17 2021/12/12 15:20:00 taca Exp $
#

MODNAME=		ssh2
PECL_VERSION=		1.3.1
CATEGORIES+=		security

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.libssh2.org/
COMMENT=		PHP bindings to the functions of libssh2
LICENSE=		php

CONFLICTS=	${PHP_PKG_PREFIX}-${MODNAME}<1.0

CONFIGURE_ARGS+=	--with-ssh2=${PREFIX}

PHP_VERSIONS_INCOMPATIBLE=	56

.include "../../security/libssh2/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
