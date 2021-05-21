# $NetBSD: Makefile,v 1.3 2021/05/21 12:40:22 nia Exp $

DISTNAME=	color-japanese-1.0.0
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://color-japanese.rubyforge.org/
COMMENT=	Defines RGB value for Japanese color names
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-color-tools>0:../../graphics/ruby-color-tools
DEPENDS+=	${RUBY_PKGPREFIX}-hoe>=1.2.0:../../devel/hoe

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} jcolorc jcolorc${RUBY_SUFFIX}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
