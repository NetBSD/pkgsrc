# $NetBSD: Makefile,v 1.18 2024/03/24 13:43:38 taca Exp $

DISTNAME=	cucumber-core-13.0.2
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://cukes.info/
COMMENT=	Core library for the Cucumber BDD app
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-gherkin>=27<28:../../lang/ruby-cucumber-gherkin
DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-messages>=20<23:../../devel/ruby-cucumber-messages
DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-tag-expressions>=5.0<7:../../devel/ruby-cucumber-tag-expressions

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
