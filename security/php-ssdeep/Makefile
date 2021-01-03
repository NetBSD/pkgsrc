# $NetBSD: Makefile,v 1.7 2021/01/03 07:36:42 taca Exp $
#

MODNAME=		ssdeep
PECL_VERSION=		1.1.0
CATEGORIES+=		security

MAINTAINER=		khorben@defora.org
HOMEPAGE=		https://treffynnon.github.io/php_ssdeep/
COMMENT=		PHP extension for ssdeep
LICENSE=		artistic

CONFIGURE_ARGS+=	--with-ssdeep=${PREFIX}

CONFLICTS=		php-ssdeep-[0-9]*

.include "../../lang/php/ext.mk"
.include "../../security/ssdeep/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
