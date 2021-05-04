# $NetBSD: Makefile,v 1.5 2021/05/04 15:10:45 taca Exp $

DISTNAME=	tty-prompt-0.23.1
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
