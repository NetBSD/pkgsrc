# $NetBSD: Makefile,v 1.13 2020/01/18 15:11:40 taca Exp $

DISTNAME=	awesome_nested_set-3.2.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	databases ruby

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/collectiveidea/awesome_nested_set
COMMENT=	Awesome nested set implementation for Active Record
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVERECORD_DEPENDS}

RUBY_RAILS_ACCEPTED=	# defined
USE_LANGUAGES=		# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
