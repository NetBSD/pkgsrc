# $NetBSD: Makefile,v 1.28 2026/08/12 15:49:39 taca Exp $

DISTNAME=	sprockets-4.3.0
CATEGORIES=	misc www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rails/sprockets
COMMENT=	Rack-based asset packaging system
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rack>=2.2.4<4:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-concurrent-ruby>=1.1<2:../../devel/ruby-concurrent-ruby

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
