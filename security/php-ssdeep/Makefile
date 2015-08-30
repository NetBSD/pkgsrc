# $NetBSD: Makefile,v 1.3 2015/08/30 14:52:39 taca Exp $
#

MODNAME=		ssdeep
PECL_VERSION=		1.0.4
CATEGORIES+=		security

MAINTAINER=		khorben@defora.org
HOMEPAGE=		http://treffynnon.github.io/php_ssdeep/
COMMENT=		PHP extension for ssdeep
LICENSE=		artistic

CONFIGURE_ARGS+=	--with-ssdeep=${PREFIX}

CONFLICTS=		php-ssdeep-[0-9]*

.include "../../lang/php/ext.mk"
.include "../../security/ssdeep/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
