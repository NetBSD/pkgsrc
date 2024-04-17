# $NetBSD: Makefile,v 1.9 2024/04/17 10:38:35 wiz Exp $

DISTNAME=	cucumber-gherkin-27.0.0
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cucumber/gherkin
COMMENT=	Gherkin parser/compiler for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-messages>=19.1.4<23:../../devel/ruby-cucumber-messages

CONFLICTS+=	ruby[0-9]*-gherkin-[0-9]*

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
