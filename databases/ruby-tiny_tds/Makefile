# $NetBSD: Makefile,v 1.13 2017/09/16 19:26:45 wiz Exp $

DISTNAME=	tiny_tds-0.7.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	databases ruby

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rails-sqlserver/tiny_tds
COMMENT=	Modern, simple and fast FreeTDS library for Ruby using DB-Library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mini_portile>=0.6.2:../../misc/ruby-mini_portile

OVERRIDE_GEMSPEC+=	mini_portile>=0.6.2

.include "../../databases/freetds/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
