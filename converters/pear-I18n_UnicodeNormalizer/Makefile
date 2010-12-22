# $NetBSD: Makefile,v 1.1.1.1 2010/12/22 15:12:29 taca Exp $

DISTNAME=	I18N_UnicodeNormalizer-1.0.0
CATEGORIES+=	converters

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	PHP classes to provide Unicode Normalization

PKG_DESTDIR_SUPPORT=	user-destdir

LICENSE=	2-clause-bsd

DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=5.0:../../converters/php-mbstring

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
