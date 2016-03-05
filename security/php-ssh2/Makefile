# $NetBSD: Makefile,v 1.5 2016/03/05 11:29:24 jperkin Exp $
#

MODNAME=		ssh2
PECL_VERSION=		0.12
PKGREVISION=		3
CATEGORIES+=		security

MAINTAINER=		filip@joyent.com
HOMEPAGE=		http://www.libssh2.org/
COMMENT=		PHP bindings to the functions of libssh2
LICENSE=		php

CONFLICTS=		php-ssh2-[0-9]*

PHP_VERSIONS_ACCEPTED=	55 56

CONFIGURE_ARGS+=	--with-ssh2=${PREFIX}
#WRKSRC=			${WRKDIR}/${MODNAME}-${PECL_VERSION}

.include "../../security/libssh2/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
