# $NetBSD: Makefile,v 1.12 2015/08/30 14:54:49 taca Exp $
#

MODNAME=		suhosin
DISTNAME=		suhosin-${PECL_VERSION}
PECL_VERSION=		0.9.38
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES=		www
MASTER_SITES=		https://download.suhosin.org/
# Do not remove EXTRACT_SUFX.
EXTRACT_SUFX=		.tar.gz

MAINTAINER=		cg@cgall.de
HOMEPAGE=		http://www.suhosin.org/
COMMENT=		Advanced protection system for PHP installations
LICENSE=		php

CONFIGURE_ARGS=		--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
