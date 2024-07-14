# $NetBSD: Makefile,v 1.24 2024/07/14 15:45:52 taca Exp $

DISTNAME=	async-2.14.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/socketry/async
COMMENT=	Concurrency framework for Ruby
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-console>=1.25.2<2:../../devel/ruby-console
DEPENDS+=	${RUBY_PKGPREFIX}-io-event>=1.6.5<2:../../devel/ruby-io-event
DEPENDS+=	${RUBY_PKGPREFIX}-fiber-annotation>=0:../../devel/ruby-fiber-annotation

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
