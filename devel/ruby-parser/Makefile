# $NetBSD: Makefile,v 1.49 2026/02/11 06:37:35 taca Exp $

DISTNAME=	ruby_parser-3.22.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby_//}
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/seattlerb/ruby_parser
COMMENT=	Ruby parser written in pure ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-ast>=2.4.1<2.5:../../devel/ruby-ast
DEPENDS+=	${RUBY_PKGPREFIX}-sexp-processor>=4.16<5:../../devel/ruby-sexp-processor

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
