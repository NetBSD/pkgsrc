# $NetBSD: Makefile,v 1.1 2013/06/05 19:57:01 khorben Exp $
#

MODNAME=		ssdeep
PECL_VERSION=		1.0.2
CATEGORIES+=		security

MAINTAINER=		khorben@defora.org
HOMEPAGE=		http://treffynnon.github.io/php_ssdeep/
COMMENT=		PHP extension for ssdeep
LICENSE=		artistic

CONFLICTS=		php-ssdeep-[0-9]*

.include "../../lang/php/ext.mk"
.include "../../security/ssdeep/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
