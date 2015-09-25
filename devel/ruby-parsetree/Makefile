# $NetBSD: Makefile,v 1.9 2015/09/25 08:53:59 taca Exp $

DISTNAME=	ParseTree-3.0.9
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/seattlerb/parsetree
COMMENT=	Extract and enumerate Ruby parse trees
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-inline>=3.7.0:../../devel/ruby-inline
DEPENDS+=	${RUBY_PKGPREFIX}-sexp-processor>=3.0.0:../../devel/ruby-sexp-processor

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
