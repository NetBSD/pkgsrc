# $NetBSD: Makefile,v 1.10.4.1 2022/03/03 19:15:19 bsiegert Exp $

DISTNAME=	Crypt_GPG-1.6.7
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Object oriented interface to GNU Privacy Guard
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Console_CommandLine>=1.1.10:../../devel/pear-Console_CommandLine

# maybe resides in lang/php/phpversion.mk
REPLACE_INTERPRETER+=	php
REPLACE.php.old=	.*php[^ ]*
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php=	scripts/crypt-gpg-pinentry

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
