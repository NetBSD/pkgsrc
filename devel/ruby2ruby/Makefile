# $NetBSD: Makefile,v 1.26 2026/02/02 15:18:52 taca Exp $

DISTNAME=	ruby2ruby-2.6.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/seattlerb/ruby2ruby
COMMENT=	Pure Ruby code from Ruby S-expressions
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sexp-processor>=4.6<5:../../devel/ruby-sexp-processor

RUBYGEM_OPTIONS+=	--format-executable

USE_LANGUAGES=	# empty

pre-build:
	${CHMOD} 0755 ${WRKSRC}/bin/r2r_show

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
