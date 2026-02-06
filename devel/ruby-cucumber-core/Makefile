# $NetBSD: Makefile,v 1.21 2026/02/06 08:28:18 wiz Exp $

DISTNAME=	cucumber-core-15.4.0
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
#HOMEPAGE=	http://cukes.info/
COMMENT=	Core library for the Cucumber BDD app
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-gherkin>=27<40:../../lang/ruby-cucumber-gherkin
DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-messages>=26<33:../../devel/ruby-cucumber-messages
DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-tag-expressions>=5<9:../../devel/ruby-cucumber-tag-expressions

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
