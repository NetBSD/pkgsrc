# $NetBSD: Makefile,v 1.31 2025/02/23 14:00:54 taca Exp $

DISTNAME=	async-2.23.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/socketry/async
COMMENT=	Concurrency framework for Ruby
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-console>=1.29<2:../../devel/ruby-console
DEPENDS+=	${RUBY_PKGPREFIX}-io-event>=1.7<2:../../devel/ruby-io-event
DEPENDS+=	${RUBY_PKGPREFIX}-fiber-annotation>=0:../../devel/ruby-fiber-annotation
DEPENDS+=	${RUBY_PKGPREFIX}-traces>=0.15<1:../../devel/ruby-traces
DEPENDS+=	${RUBY_PKGPREFIX}-metrics>=0.12<1:../../devel/ruby-metrics

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
