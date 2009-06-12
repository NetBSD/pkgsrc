# $NetBSD: Makefile,v 1.3 2009/06/12 05:21:45 taca Exp $

DISTNAME=	heckle-1.4.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://seattlerb.rubyforge.org/heckle/
COMMENT=	Code mutation tester for Ruby
LICENSE=	mit

DEPENDS+=	hoe>=1.2.1:../../devel/hoe
DEPENDS+=	${RUBY_PKGPREFIX}-ruby2ruby>=1.1.0:../../devel/ruby2ruby
DEPENDS+=	ZenTest>=3.5.2:../../devel/ZenTest

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
