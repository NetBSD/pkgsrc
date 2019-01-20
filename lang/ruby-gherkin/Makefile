# $NetBSD: Makefile,v 1.5 2019/01/20 13:40:44 taca Exp $

DISTNAME=	gherkin-6.0.15
CATEGORIES=	lang

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/cucumber/cucumber/tree/master/gherkin
COMMENT=	Parser and compiler for the Gherkin language
LICENSE=	mit

RUBYGEM_OPTIONS+=	--format-executable

DEPENDS+=	${RUBY_PKGPREFIX}-c21e>=1.1.8<2:../../devel/ruby-c21e
DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-messages>=2.0.0<2.1:../../devel/ruby-cucumber-messages

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
