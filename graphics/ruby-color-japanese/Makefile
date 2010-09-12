# $NetBSD: Makefile,v 1.1.1.1 2010/09/12 01:43:31 taca Exp $

DISTNAME=	color-japanese-1.0.0
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://color-japanese.rubyforge.org/
COMMENT=	Defines RGB value for Japanese color names
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-color-tools>0:../../graphics/ruby-color-tools
DEPENDS+=	${RUBY_PKGPREFIX}-hoe>=1.2.0:../../devel/hoe

CONFLICTS+=	ruby[1-9][0-9]-color-japanese-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
