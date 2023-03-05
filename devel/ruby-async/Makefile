# $NetBSD: Makefile,v 1.6 2023/03/05 13:35:42 taca Exp $

DISTNAME=	async-2.4.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/socketry/async
COMMENT=	Concurrency framework for Ruby
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-console>=1.10<2:../../devel/ruby-console
DEPENDS+=	${RUBY_PKGPREFIX}-io-event>=1.1.0<2:../../devel/ruby-io-event
DEPENDS+=	${RUBY_PKGPREFIX}-timers>=4.1<5:../../time/ruby-timers

RUBY_VERSIONS_ACCEPTED=	31 32

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
