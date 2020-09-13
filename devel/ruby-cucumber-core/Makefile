# $NetBSD: Makefile,v 1.9 2020/09/13 15:36:13 taca Exp $

DISTNAME=	cucumber-core-8.0.1
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://cukes.info/
COMMENT=	Core library for the Cucumber BDD app
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-gherkin>=15.0<16:../../lang/ruby-cucumber-gherkin
DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-messages>=13.0<14:../../devel/ruby-cucumber-messages
DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-tag_expressions>=2.0<3:../../devel/ruby-cucumber-tag_expressions

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
