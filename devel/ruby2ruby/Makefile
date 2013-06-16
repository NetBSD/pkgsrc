# $NetBSD: Makefile,v 1.10 2013/06/16 16:55:49 taca Exp $

DISTNAME=	ruby2ruby-2.0.5
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://seattlerb.rubyforge.org/
COMMENT=	Pure Ruby code from Ruby S-expressions
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sexp-processor>=4.0<5:../../devel/ruby-sexp-processor
DEPENDS+=	${RUBY_PKGPREFIX}-parser>=3.1<4:../../devel/ruby-parser

CONFLICTS+=	ruby[1-9][0-9]-ruby2ruby-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
