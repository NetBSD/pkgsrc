# $NetBSD: Makefile,v 1.1 2019/02/03 14:58:16 taca Exp $

DISTNAME=	i18n-1.2.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/i18n/i18n12/}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/svenfuchs/i18n
COMMENT=	New wave Internationalization support for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-concurrent-ruby>=1.0<2:../../devel/ruby-concurrent-ruby

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
