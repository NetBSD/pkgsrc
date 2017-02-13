# $NetBSD: Makefile,v 1.1 2017/02/13 03:22:02 minskim Exp $

DISTNAME=	cucumber-core-2.0.0
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://cukes.info/
COMMENT=	Core library for the Cucumber BDD app
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-backports>=3.6.0:../../devel/ruby-backports
DEPENDS+=	${RUBY_PKGPREFIX}-gherkin>=4.0.0:../../lang/ruby-gherkin

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
