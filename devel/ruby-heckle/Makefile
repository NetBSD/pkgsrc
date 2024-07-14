# $NetBSD: Makefile,v 1.9 2024/07/14 07:13:08 taca Exp $

DISTNAME=	heckle-1.4.3
PKGREVISION=	3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://docs.seattlerb.org/heckle/
COMMENT=	Code mutation tester for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-hoe>=2.3.0:../../devel/ruby-hoe
DEPENDS+=	${RUBY_PKGPREFIX}-parsetree>=2.0.0:../../devel/ruby-parsetree
DEPENDS+=	${RUBY_PKGPREFIX}-ruby2ruby>=1.1.6:../../devel/ruby2ruby
DEPENDS+=	${RUBY_PKGPREFIX}-ZenTest>=3.5.2:../../devel/ruby-ZenTest

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
