# $NetBSD: Makefile,v 1.2 2024/07/20 15:28:19 taca Exp $

DISTNAME=	youplot-0.4.6
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/red-data-tools/YouPlot
COMMENT=	Command line tool that draws plots on the terminal
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-unicode_plot>=0.0.5:../../graphics/ruby-unicode_plot

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
