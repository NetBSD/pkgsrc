# $NetBSD: Makefile,v 1.14 2026/05/31 05:59:16 taca Exp $

DISTNAME=	cucumber-gherkin-39.1.0
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cucumber/gherkin
COMMENT=	Gherkin parser/compiler for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-messages>=31<33:../../devel/ruby-cucumber-messages

CONFLICTS+=	ruby[0-9]*-gherkin-[0-9]*

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
