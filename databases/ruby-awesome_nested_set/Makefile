# $NetBSD: Makefile,v 1.6 2017/06/21 13:12:20 taca Exp $

DISTNAME=	awesome_nested_set-2.1.6
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	databases ruby

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://github.com/collectiveidea/awesome_nested_set
COMMENT=	Awesome nested set implementation for Active Record
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVERECORD_DEPENDS}

RUBY_RAILS_SUPPORTED=	32
USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
