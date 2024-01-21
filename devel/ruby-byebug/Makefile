# $NetBSD: Makefile,v 1.12 2024/01/21 09:13:54 taca Exp $

DISTNAME=	byebug-11.1.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/deivid-rodriguez/byebug
COMMENT=	Ruby 2.0 fast debugger - base + CLI
LICENSE=	2-clause-bsd

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/rubyversion.mk"
.if ${RUBY_VER} < 33
DEPENDS+=	${RUBY_PKGPREFIX}-readline>=${RUBY_VERSION}:../../devel/ruby-readline
.endif

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
