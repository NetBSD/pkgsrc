# $NetBSD: Makefile,v 1.5 2024/02/10 14:13:06 taca Exp $

DISTNAME=	roadie-5.2.1
CATEGORIES=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Mange/roadie
COMMENT=	Making HTML emails comfortable for the Ruby rockstars
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.15<2:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-css-parser>=1.4<2:../../www/ruby-css-parser

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
