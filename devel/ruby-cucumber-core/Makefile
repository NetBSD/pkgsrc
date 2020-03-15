# $NetBSD: Makefile,v 1.7 2020/03/15 17:27:54 taca Exp $

DISTNAME=	cucumber-core-6.0.0
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://cukes.info/
COMMENT=	Core library for the Cucumber BDD app
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-gherkin>=10.0.0:../../lang/ruby-cucumber-gherkin
DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-messages>=10.0<11:../../devel/ruby-cucumber-messages
DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-tag_expressions>=2.0<3:../../devel/ruby-cucumber-tag_expressions

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
