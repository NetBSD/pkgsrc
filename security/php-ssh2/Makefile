# $NetBSD: Makefile,v 1.3 2015/07/26 18:07:55 nros Exp $
#

MODNAME=		ssh2
PECL_VERSION=		0.12
PKGREVISION=		2
CATEGORIES+=		security

MAINTAINER=		filip@joyent.com
HOMEPAGE=		http://www.libssh2.org/
COMMENT=		PHP bindings to the functions of libssh2
LICENSE=		php

CONFLICTS=		php-ssh2-[0-9]*

CONFIGURE_ARGS+=	--with-ssh2=${PREFIX}
#WRKSRC=			${WRKDIR}/${MODNAME}-${PECL_VERSION}

.include "../../security/libssh2/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
