# $NetBSD: Makefile,v 1.7 2023/08/08 11:55:08 tsutsui Exp $

DISTNAME=	simpleidn-0.2.1
PKGNAME=        ${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mmriis/simpleidn
COMMENT=	Punycode ACE to unicode UTF-8 (and vice-verse) string conversion
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-unf>=0.1.4<0.2:../../converters/ruby-unf

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
