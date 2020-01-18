# $NetBSD: Makefile,v 1.6 2020/01/18 16:30:45 taca Exp $

DISTNAME=	gherkin-9.0.0
CATEGORIES=	lang

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/cucumber/cucumber/tree/master/gherkin
COMMENT=	Parser and compiler for the Gherkin language
LICENSE=	mit

RUBYGEM_OPTIONS+=	--format-executable

DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-messages>=7.0.0:../../devel/ruby-cucumber-messages

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
