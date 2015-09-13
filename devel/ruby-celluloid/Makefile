# $NetBSD: Makefile,v 1.2 2015/09/13 14:19:06 taca Exp $

DISTNAME=	celluloid-0.17.1.2
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

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
