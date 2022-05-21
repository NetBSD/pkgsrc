# $NetBSD: Makefile,v 1.8 2022/05/21 16:22:55 taca Exp $
#

MODNAME=		ssdeep
PECL_VERSION=		1.1.0
CATEGORIES+=		security

MAINTAINER=		khorben@defora.org
HOMEPAGE=		https://github.com/php/pecl-text-ssdeep
COMMENT=		PHP extension for ssdeep
LICENSE=		artistic

PHP_VERSIONS_ACCEPTED=	56 74

CONFIGURE_ARGS+=	--with-ssdeep=${PREFIX}

CONFLICTS=		php-ssdeep-[0-9]*

.include "../../lang/php/ext.mk"
.include "../../security/ssdeep/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
