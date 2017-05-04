# $NetBSD: Makefile,v 1.4 2017/05/04 15:03:59 taca Exp $

DISTNAME=	awesome_nested_set-2.1.6
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	databases ruby

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://github.com/collectiveidea/awesome_nested_set
COMMENT=	Awesome nested set implementation for Active Record
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-activerecord>=3.0.0:${RUBY_RAILS32_ACTIVERECORD}

RUBY_RAILS_SUPPORTED=	32
USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../lang/ruby/rails.mk"
.include "../../mk/bsd.pkg.mk"
