# $NetBSD: Makefile,v 1.15 2022/02/12 12:23:14 taca Exp $

DISTNAME=	cucumber-core-10.1.1
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://cukes.info/
COMMENT=	Core library for the Cucumber BDD app
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-gherkin>=22.0<23:../../lang/ruby-cucumber-gherkin
DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-messages>=17.1<18:../../devel/ruby-cucumber-messages
DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-tag-expressions>=4.0<5:../../devel/ruby-cucumber-tag-expressions

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
