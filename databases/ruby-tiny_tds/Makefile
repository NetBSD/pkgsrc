# $NetBSD: Makefile,v 1.1 2014/07/05 12:29:25 rodent Exp $

DISTNAME=	tiny_tds-0.6.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	databases ruby

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://github.com/rails-sqlserver/tiny_tds
COMMENT=	Modern, simple and fast FreeTDS library for Ruby using DB-Library
LICENSE=	mit

.include "../../databases/freetds/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
