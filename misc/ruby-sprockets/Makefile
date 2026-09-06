# $NetBSD: Makefile,v 1.29 2026/09/06 15:06:19 taca Exp $

DISTNAME=	sprockets-4.4.1
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
