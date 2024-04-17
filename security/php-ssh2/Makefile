# $NetBSD: Makefile,v 1.19 2024/04/17 10:38:36 wiz Exp $

MODNAME=		ssh2
PECL_VERSION=		1.3.1
CATEGORIES+=		security

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.libssh2.org/
COMMENT=		PHP bindings to the functions of libssh2
PKGREVISION=		1
LICENSE=		php

CONFIGURE_ARGS+=	--with-ssh2=${PREFIX}

PHP_VERSIONS_INCOMPATIBLE=	56

.include "../../security/libssh2/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
