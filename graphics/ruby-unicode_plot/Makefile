# $NetBSD: Makefile,v 1.1 2023/01/31 13:06:53 wiz Exp $

DISTNAME=	unicode_plot-0.0.5
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/red-data-tools/unicode_plot.rb
COMMENT=	Plot your data by Unicode characters
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-enumerable-statistics>=2.0.1:../../math/ruby-enumerable-statistics

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
