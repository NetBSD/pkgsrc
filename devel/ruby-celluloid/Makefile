# $NetBSD: Makefile,v 1.5 2019/01/20 13:21:49 taca Exp $

DISTNAME=	celluloid-0.17.4
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/celluloid/celluloid
COMMENT=	Actor-based concurrent object framework for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-celluloid-essentials>=0.20:../../devel/ruby-celluloid-essentials
DEPENDS+=	${RUBY_PKGPREFIX}-celluloid-supervision>=0.20:../../devel/ruby-celluloid-supervision
DEPENDS+=	${RUBY_PKGPREFIX}-celluloid-pool>=0.20:../../devel/ruby-celluloid-pool
DEPENDS+=	${RUBY_PKGPREFIX}-celluloid-fsm>=0.20:../../devel/ruby-celluloid-fsm
DEPENDS+=	${RUBY_PKGPREFIX}-celluloid-extras>=0.20:../../devel/ruby-celluloid-extras
DEPENDS+=	${RUBY_PKGPREFIX}-timers>=4.1.1:../../time/ruby-timers

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
