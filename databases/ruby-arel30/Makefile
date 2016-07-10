# $NetBSD: Makefile,v 1.2 2016/07/10 10:20:31 rillig Exp $

DISTNAME=	arel-3.0.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/arel/arel30/}
PKGREVISION=	1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/rails/arel
COMMENT=	Arel is a SQL AST manager for Ruby
LICENSE=	mit

CONFLICTS=	${RUBY_PKGPREFIX}-arel<3.1

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
