# $NetBSD: Makefile,v 1.6 2020/01/18 15:18:26 taca Exp $

DISTNAME=	cucumber-core-5.0.2
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://cukes.info/
COMMENT=	Core library for the Cucumber BDD app
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-backports>=3.8.0:../../devel/ruby-backports
DEPENDS+=	${RUBY_PKGPREFIX}-gherkin>=6.0.0:../../lang/ruby-gherkin
DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-tag_expressions>=1.1.0:../../devel/ruby-cucumber-tag_expressions

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
