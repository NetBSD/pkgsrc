# $NetBSD: Makefile,v 1.9 2024/05/05 16:52:47 taca Exp $

DISTNAME=	simpleidn-0.2.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mmriis/simpleidn
COMMENT=	Punycode ACE to unicode UTF-8 (and vice-verse) string conversion
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-unf>=0.1.4<0.2:../../converters/ruby-unf

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
