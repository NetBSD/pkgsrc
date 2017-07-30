# $NetBSD: Makefile,v 1.12 2017/07/30 22:32:14 wiz Exp $

DISTNAME=	tiny_tds-0.7.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	databases ruby

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/rails-sqlserver/tiny_tds
COMMENT=	Modern, simple and fast FreeTDS library for Ruby using DB-Library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mini_portile>=0.6.2:../../misc/ruby-mini_portile

OVERRIDE_GEMSPEC+=	mini_portile>=0.6.2

.include "../../databases/freetds/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
