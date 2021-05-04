# $NetBSD: Makefile,v 1.24 2021/05/04 14:11:36 taca Exp $

DISTNAME=	i18n-1.8.10
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/svenfuchs/i18n
COMMENT=	New wave Internationalization support for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-concurrent-ruby>=1.0<2:../../devel/ruby-concurrent-ruby

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
