# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:17:14 jlam Exp $

DISTNAME=	heckle-1.4.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://seattlerb.rubyforge.org/heckle/
COMMENT=	Code mutation tester for Ruby

DEPENDS+=	hoe>=1.2.1:../../devel/hoe
DEPENDS+=	${RUBY_PKGPREFIX}-ruby2ruby>=1.1.0:../../devel/ruby2ruby
DEPENDS+=	ZenTest>=3.5.2:../../devel/ZenTest

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
