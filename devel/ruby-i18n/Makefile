# $NetBSD: Makefile,v 1.30 2024/03/10 15:06:25 taca Exp $

DISTNAME=	i18n-1.14.4
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/svenfuchs/i18n
COMMENT=	New wave Internationalization support for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-concurrent-ruby>=1.0<2:../../devel/ruby-concurrent-ruby

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
