# $NetBSD: Makefile,v 1.10 2024/09/22 13:46:43 taca Exp $

DISTNAME=	cucumber-gherkin-29.0.0
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cucumber/gherkin
COMMENT=	Gherkin parser/compiler for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-messages>=25<26:../../devel/ruby-cucumber-messages

CONFLICTS+=	ruby[0-9]*-gherkin-[0-9]*

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
