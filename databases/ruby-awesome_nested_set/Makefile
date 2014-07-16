# $NetBSD: Makefile,v 1.2 2014/07/16 07:56:28 rodent Exp $

DISTNAME=	awesome_nested_set-2.1.6
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases ruby

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://github.com/collectiveidea/awesome_nested_set
COMMENT=	Awesome nested set implementation for Active Record
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-activerecord>=3.0.0:../../databases/ruby-activerecord32

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
