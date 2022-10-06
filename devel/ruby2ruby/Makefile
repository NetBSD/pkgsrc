# $NetBSD: Makefile,v 1.22 2022/10/06 14:30:53 taca Exp $

DISTNAME=	ruby2ruby-2.5.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/seattlerb/ruby2ruby
COMMENT=	Pure Ruby code from Ruby S-expressions
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sexp-processor>=4.6<5:../../devel/ruby-sexp-processor
DEPENDS+=	${RUBY_PKGPREFIX}-parser>=3.1<4:../../devel/ruby-parser

RUBYGEM_OPTIONS+=	--format-executable

USE_LANGUAGES=	# empty

pre-build:
	${CHMOD} 0755 ${WRKSRC}/bin/r2r_show

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
