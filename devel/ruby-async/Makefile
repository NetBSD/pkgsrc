# $NetBSD: Makefile,v 1.19 2024/04/07 14:39:33 taca Exp $

DISTNAME=	async-2.10.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/socketry/async
COMMENT=	Concurrency framework for Ruby
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-console>=1.10<2:../../devel/ruby-console
DEPENDS+=	${RUBY_PKGPREFIX}-io-event>=1.5.1<2:../../devel/ruby-io-event
DEPENDS+=	${RUBY_PKGPREFIX}-timers>=4.1<5:../../time/ruby-timers
DEPENDS+=	${RUBY_PKGPREFIX}-fiber-annotation>=0:../../devel/ruby-fiber-annotation

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
