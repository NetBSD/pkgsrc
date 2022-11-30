# $NetBSD: Makefile,v 1.1 2022/11/30 14:26:19 taca Exp $

DISTNAME=	tty-logger-0.6.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ttytoolkit.org/
COMMENT=	Readable, structured and beautiful terminal logging
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-pastel>=0.8<1:../../devel/ruby-pastel

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
