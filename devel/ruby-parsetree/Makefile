# $NetBSD: Makefile,v 1.5 2011/06/18 01:50:36 taca Exp $

DISTNAME=	ParseTree-3.0.7
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://parsetree.rubyforge.org/
COMMENT=	Extract and enumerate Ruby parse trees
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-inline>=3.7.0:../../devel/ruby-inline
DEPENDS+=	${RUBY_PKGPREFIX}-sexp-processor>=3.0.0:../../devel/ruby-sexp-processor

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
