# $NetBSD: Makefile,v 1.21 2024/06/08 15:40:38 taca Exp $

DISTNAME=	async-2.12.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/socketry/async
COMMENT=	Concurrency framework for Ruby
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-console>=1.25.2<2:../../devel/ruby-console
DEPENDS+=	${RUBY_PKGPREFIX}-io-event>=1.5.1<2:../../devel/ruby-io-event
DEPENDS+=	${RUBY_PKGPREFIX}-fiber-annotation>=0:../../devel/ruby-fiber-annotation

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
