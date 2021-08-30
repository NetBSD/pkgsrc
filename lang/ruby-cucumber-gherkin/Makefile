# $NetBSD: Makefile,v 1.6 2021/08/30 16:24:39 taca Exp $

DISTNAME=	cucumber-gherkin-20.0.1
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cucumber/gherkin-ruby
COMMENT=	Gherkin parser/compiler for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-messages>=17.0<18:../../devel/ruby-cucumber-messages

CONFLICTS+=	${RUBY_PKGPREFIX}-gherkin-[0-9]*

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
