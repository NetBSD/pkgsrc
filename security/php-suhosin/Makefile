# $NetBSD: Makefile,v 1.11 2015/03/15 00:35:14 taca Exp $
#

MODNAME=		suhosin
DISTNAME=		suhosin-${PECL_VERSION}
PECL_VERSION=		0.9.37.1
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES=		www
MASTER_SITES=		https://download.suhosin.org/
# Do not remove EXTRACT_SUFX.
EXTRACT_SUFX=		.tar.gz

MAINTAINER=		cg@cgall.de
HOMEPAGE=		http://www.suhosin.org/
COMMENT=		Advanced protection system for PHP installations

CONFIGURE_ARGS=		--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
