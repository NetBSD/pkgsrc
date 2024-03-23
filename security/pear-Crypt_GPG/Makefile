# $NetBSD: Makefile,v 1.15 2024/03/23 16:09:47 taca Exp $

DISTNAME=	Crypt_GPG-1.6.9
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Object oriented interface to GNU Privacy Guard
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=${PHP_VERSION}:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Console_CommandLine>=1.1.10:../../devel/pear-Console_CommandLine

REPLACE_PHP+=	scripts/crypt-gpg-pinentry

.include "../../lang/php/replace.mk"
.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
