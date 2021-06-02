# $NetBSD: Makefile,v 1.4 2021/06/02 15:50:34 taca Exp $

DISTNAME=	color-japanese-1.0.0
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://color-japanese.rubyforge.org/
COMMENT=	Defines RGB value for Japanese color names
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-color-tools>0:../../graphics/ruby-color-tools
DEPENDS+=	${RUBY_PKGPREFIX}-hoe>=1.2.0:../../devel/hoe

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
