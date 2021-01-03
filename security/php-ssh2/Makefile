# $NetBSD: Makefile,v 1.16 2021/01/03 07:38:19 taca Exp $
#

MODNAME=		ssh2
PECL_VERSION=		1.2
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
