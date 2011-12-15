# $NetBSD: Makefile,v 1.7 2011/12/15 15:12:41 taca Exp $

DISTNAME=	ruby2ruby-1.3.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://seattlerb.rubyforge.org/
COMMENT=	Pure Ruby code from Ruby S-expressions
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sexp-processor>=3.0<4:../../devel/ruby-sexp-processor
DEPENDS+=	${RUBY_PKGPREFIX}-parser>=2.0<3:../../devel/ruby-parser

CONFLICTS+=	ruby[1-9][0-9]-ruby2ruby-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
