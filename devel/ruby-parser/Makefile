# $NetBSD: Makefile,v 1.21 2015/12/12 04:10:02 taca Exp $

DISTNAME=	ruby_parser-3.7.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby_//}
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/seattlerb/ruby_parser
COMMENT=	Ruby parser written in pure ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sexp-processor>=4.1<5:../../devel/ruby-sexp-processor

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
