# $NetBSD: Makefile,v 1.2 2020/03/15 17:12:59 taca Exp $

DISTNAME=	tty-prompt-0.21.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://piotrmurach.github.io/tty
COMMENT=	Beautiful and powerful interactive command line prompt
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-necromancer>=0.6:../../devel/ruby-necromancer
DEPENDS+=	${RUBY_PKGPREFIX}-pastel>=0.7.0<0.8:../../devel/ruby-pastel
DEPENDS+=	${RUBY_PKGPREFIX}-tty-reader>=0.7.0<0.8:../../devel/ruby-tty-reader

USE_LANGUAGES=	# none

OVERRIDE_GEMSPEC=	necromancer>=0.6

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
