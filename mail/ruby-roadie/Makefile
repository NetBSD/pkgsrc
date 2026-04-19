# $NetBSD: Makefile,v 1.6 2026/04/19 14:14:17 taca Exp $

DISTNAME=	roadie-5.3.0
CATEGORIES=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Mange/roadie
COMMENT=	Making HTML emails comfortable for the Ruby rockstars
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.15<2:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-css-parser>=1.4<3:../../www/ruby-css-parser

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
