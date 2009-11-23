# $NetBSD: Makefile,v 1.3 2009/11/23 14:13:28 fhajny Exp $

DISTNAME=	ruby2ruby-1.2.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://seattlerb.rubyforge.org/
COMMENT=	Pure Ruby code from Ruby S-expressions

DEPENDS+=	${RUBY_PKGPREFIX}-parsetree>=3.0:../../devel/ruby-parsetree
DEPENDS+=	${RUBY_PKGPREFIX}-sexp-processor>=3.0:../../devel/ruby-sexp-processor
DEPENDS+=	${RUBY_PKGPREFIX}-parser>=2.0:../../devel/ruby-parser
DEPENDS+=	hoe>=2.3.3:../../devel/hoe

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
