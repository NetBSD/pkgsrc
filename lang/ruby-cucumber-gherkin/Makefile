# $NetBSD: Makefile,v 1.7 2021/11/23 14:05:24 taca Exp $

DISTNAME=	cucumber-gherkin-22.0.0
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cucumber/gherkin-ruby
COMMENT=	Gherkin parser/compiler for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-messages>=17.1<18:../../devel/ruby-cucumber-messages

CONFLICTS+=	${RUBY_PKGPREFIX}-gherkin-[0-9]*

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
