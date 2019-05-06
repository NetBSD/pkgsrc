# $NetBSD: Makefile,v 1.8 2019/05/06 05:20:26 taca Exp $

DISTNAME=	byebug-11.0.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/deivid-rodriguez/byebug
COMMENT=	Ruby 2.0 fast debugger - base + CLI
LICENSE=	2-clause-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-readline>=${RUBY_VERSION_FULL}:../../devel/ruby-readline

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
