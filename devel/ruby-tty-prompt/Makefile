# $NetBSD: Makefile,v 1.4 2021/01/11 13:28:12 taca Exp $

DISTNAME=	tty-prompt-0.23.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ttytoolkit.org/
COMMENT=	Beautiful and powerful interactive command line prompt
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-pastel>=0.8<1:../../devel/ruby-pastel
DEPENDS+=	${RUBY_PKGPREFIX}-tty-reader>=0.8<1:../../devel/ruby-tty-reader

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
