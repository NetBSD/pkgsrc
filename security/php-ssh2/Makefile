# $NetBSD: Makefile,v 1.20 2025/02/08 03:51:48 taca Exp $

MODNAME=		ssh2
PECL_VERSION=		1.3.1
PKGREVISION=		2
CATEGORIES+=		security

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.libssh2.org/
COMMENT=		PHP bindings to the functions of libssh2
LICENSE=		php

CONFIGURE_ARGS+=	--with-ssh2=${PREFIX}

PHP_VERSIONS_INCOMPATIBLE=	56

.include "../../security/libssh2/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
