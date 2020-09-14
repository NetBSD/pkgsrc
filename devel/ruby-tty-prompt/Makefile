# $NetBSD: Makefile,v 1.3 2020/09/14 00:16:20 taca Exp $

DISTNAME=	tty-prompt-0.22.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://piotrmurach.github.io/tty
COMMENT=	Beautiful and powerful interactive command line prompt
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-pastel>=0.8<1:../../devel/ruby-pastel
DEPENDS+=	${RUBY_PKGPREFIX}-tty-reader>=0.8<1:../../devel/ruby-tty-reader

USE_LANGUAGES=	# none

OVERRIDE_GEMSPEC=	necromancer>=0.6

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
