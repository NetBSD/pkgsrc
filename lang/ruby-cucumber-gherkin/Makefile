# $NetBSD: Makefile,v 1.4 2021/05/23 09:37:06 taca Exp $

DISTNAME=	cucumber-gherkin-19.0.2
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cucumber/gherkin-ruby
COMMENT=	Gherkin parser/compiler for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-messages>=16.0.0:../../devel/ruby-cucumber-messages

CONFLICTS+=	${RUBY_PKGPREFIX}-gherkin-[0-9]*

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
