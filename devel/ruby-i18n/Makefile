# $NetBSD: Makefile,v 1.15 2018/09/23 14:42:41 taca Exp $

DISTNAME=	i18n-1.1.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/svenfuchs/i18n
COMMENT=	New wave Internationalization support for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-concurrent-ruby>=1.0<2:../../devel/ruby-concurrent-ruby

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
