# $NetBSD: Makefile,v 1.55 2026/09/24 04:03:44 taca Exp $

DISTNAME=	async-2.46.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/socketry/async
COMMENT=	Concurrency framework for Ruby
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-console>=1.29<2:../../devel/ruby-console
DEPENDS+=	${RUBY_PKGPREFIX}-io-event>=1.21<2:../../devel/ruby-io-event
DEPENDS+=	${RUBY_PKGPREFIX}-fiber-annotation>=0:../../devel/ruby-fiber-annotation

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
