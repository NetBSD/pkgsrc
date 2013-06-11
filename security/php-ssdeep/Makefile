# $NetBSD: Makefile,v 1.2 2013/06/11 01:12:23 khorben Exp $
#

MODNAME=		ssdeep
PECL_VERSION=		1.0.2
CATEGORIES+=		security

MAINTAINER=		khorben@defora.org
HOMEPAGE=		http://treffynnon.github.io/php_ssdeep/
COMMENT=		PHP extension for ssdeep
LICENSE=		artistic

CONFIGURE_ARGS+=	SSDEEP_INCLUDEDIR=${PREFIX}/include
CONFIGURE_ARGS+=	SSDEEP_LIB_DIR=${PREFIX}/lib

CONFLICTS=		php-ssdeep-[0-9]*

.include "../../lang/php/ext.mk"
.include "../../security/ssdeep/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
