# $NetBSD: Makefile,v 1.14 2015/06/04 14:44:58 taca Exp $

DISTNAME=	ruby2ruby-2.2.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/seattlerb/ruby2ruby
COMMENT=	Pure Ruby code from Ruby S-expressions
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sexp-processor>=4.0<5:../../devel/ruby-sexp-processor
DEPENDS+=	${RUBY_PKGPREFIX}-parser>=3.1<4:../../devel/ruby-parser

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
