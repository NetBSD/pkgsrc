# $NetBSD: Makefile,v 1.1 2016/08/21 08:26:39 taca Exp $

DISTNAME=	Crypt_GPG-1.4.2
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Object oriented interface to GNU Privacy Guard

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Console_CommandLine>=1.1.10:../../devel/pear-Console_CommandLine

# maybe resides in lang/php/phpversion.mk
REPLACE_INTERPRETER+=	php
REPLACE.php.old=	.*php[^ ]*
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php=	scripts/crypt-gpg-pinentry

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
