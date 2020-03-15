# $NetBSD: Makefile,v 1.1 2020/03/15 17:16:28 taca Exp $

DISTNAME=	cucumber-gherkin-11.0.0
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cucumber/gherkin-ruby
COMMENT=	Gherkin parser/compiler for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-messages>=10.0.1<11:../../devel/ruby-cucumber-messages

CONFLICTS+=	${RUBY_PKGPREFIX}-gherkin-[0-9]*

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
