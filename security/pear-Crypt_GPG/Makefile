# $NetBSD: Makefile,v 1.16 2025/02/08 03:51:48 taca Exp $

DISTNAME=	Crypt_GPG-1.6.9
PKGREVISION=	1
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Object oriented interface to GNU Privacy Guard
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=${PHP_BASE_VERS}:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Console_CommandLine>=1.1.10:../../devel/pear-Console_CommandLine

REPLACE_PHP+=	scripts/crypt-gpg-pinentry

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
