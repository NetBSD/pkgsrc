# $NetBSD: Makefile,v 1.4 2009/11/23 14:21:43 fhajny Exp $

DISTNAME=	heckle-1.4.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://seattlerb.rubyforge.org/heckle/
COMMENT=	Code mutation tester for Ruby
LICENSE=	mit

DEPENDS+=	hoe>=1.2.1:../../devel/hoe
DEPENDS+=	${RUBY_PKGPREFIX}-ruby2ruby>=1.1.6:../../devel/ruby2ruby
DEPENDS+=	${RUBY_PKGPREFIX}-parsetree>=2.0.0:../../devel/ruby-parsetree
DEPENDS+=	ZenTest>=3.5.2:../../devel/ZenTest

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
