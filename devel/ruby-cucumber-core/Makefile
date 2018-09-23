# $NetBSD: Makefile,v 1.3 2018/09/23 14:59:34 taca Exp $

DISTNAME=	cucumber-core-3.2.0
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://cukes.info/
COMMENT=	Core library for the Cucumber BDD app
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-backports>=3.8.0:../../devel/ruby-backports
DEPENDS+=	${RUBY_PKGPREFIX}-gherkin>=5.0.0:../../lang/ruby-gherkin
DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-tag_expressions>=1.1.0:../../devel/ruby-cucumber-tag_expressions

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
