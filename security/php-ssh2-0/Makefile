# $NetBSD: Makefile,v 1.6 2023/10/24 22:10:56 wiz Exp $
#

MODNAME=		ssh2
PECL_VERSION=		0.13
CATEGORIES+=		security

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.libssh2.org/
COMMENT=		PHP bindings to the functions of libssh2
PKGREVISION=		2
LICENSE=		php

CONFLICTS=	${PHP_PKG_PREFIX}-${MODNAME}>=1.0

PHP_VERSIONS_ACCEPTED=	56

CONFIGURE_ARGS+=	--with-ssh2=${PREFIX}
#WRKSRC=		${WRKDIR}/${MODNAME}-${PECL_VERSION}

.include "../../security/libssh2/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
