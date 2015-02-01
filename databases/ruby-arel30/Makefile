# $NetBSD: Makefile,v 1.1 2015/02/01 12:22:21 taca Exp $

DISTNAME=	arel-3.0.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/arel/arel30/}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/rails/arel
COMMENT=	Arel is a SQL AST manager for Ruby
LICENSE=	mit

CONFLICS=	${RUBY_PKGPREFIX}-arel<3.1

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
