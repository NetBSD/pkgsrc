# $NetBSD: Makefile,v 1.2 2010/09/10 06:45:00 taca Exp $

DISTNAME=	color-1.4.1
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://color.rubyforge.org/
COMMENT=	Color value conversion and manipulation library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-hoe>=1.5.1:../../devel/hoe
DEPENDS+=	${RUBY_PKGPREFIX}-archive-tar-minitar>=0.5.1:../../archivers/ruby-archive-tar-minitar

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
