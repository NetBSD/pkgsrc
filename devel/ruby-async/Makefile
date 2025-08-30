# $NetBSD: Makefile,v 1.39 2025/08/30 07:31:00 taca Exp $

DISTNAME=	async-2.28.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/socketry/async
COMMENT=	Concurrency framework for Ruby
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-console>=1.29<2:../../devel/ruby-console
DEPENDS+=	${RUBY_PKGPREFIX}-io-event>=1.12<2:../../devel/ruby-io-event
DEPENDS+=	${RUBY_PKGPREFIX}-fiber-annotation>=0:../../devel/ruby-fiber-annotation
DEPENDS+=	${RUBY_PKGPREFIX}-traces>=0.15<1:../../devel/ruby-traces
DEPENDS+=	${RUBY_PKGPREFIX}-metrics>=0.12<1:../../devel/ruby-metrics

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
