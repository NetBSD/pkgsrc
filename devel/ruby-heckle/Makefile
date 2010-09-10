# $NetBSD: Makefile,v 1.5 2010/09/10 05:48:37 taca Exp $

DISTNAME=	heckle-1.4.3
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://seattlerb.rubyforge.org/heckle/
COMMENT=	Code mutation tester for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-parsetree>=2.0.0:../../devel/ruby-parsetree
DEPENDS+=	${RUBY_PKGPREFIX}-ruby2ruby>=1.1.6:../../devel/ruby2ruby
DEPENDS+=	${RUBY_PKGPREFIX}-ZenTest>=3.5.2:../../devel/ZenTest

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
