# $NetBSD: Makefile,v 1.27 2017/04/22 16:25:55 taca Exp $

DISTNAME=	ruby_parser-3.9.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby_//}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/seattlerb/ruby_parser
COMMENT=	Ruby parser written in pure ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sexp-processor>=4.1<5:../../devel/ruby-sexp-processor

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
