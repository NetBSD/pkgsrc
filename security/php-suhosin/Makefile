# $NetBSD: Makefile,v 1.16 2025/02/08 03:51:49 taca Exp $
#

MODNAME=		suhosin
DISTNAME=		suhosin-${PECL_VERSION}
PECL_VERSION=		0.9.38
PKGREVISION=		1
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES=		www
MASTER_SITES=		https://download.suhosin.org/
# Do not remove EXTRACT_SUFX.
EXTRACT_SUFX=		.tar.gz

MAINTAINER=		cg@cgall.de
HOMEPAGE=		https://www.suhosin.org/
COMMENT=		Advanced protection system for PHP installations
LICENSE=		php

PHP_VERSIONS_ACCEPTED=	56

CONFIGURE_ARGS=		--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
