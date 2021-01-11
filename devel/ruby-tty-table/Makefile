# $NetBSD: Makefile,v 1.1 2021/01/11 13:30:38 taca Exp $

DISTNAME=	tty-table-0.12.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ttytoolkit.org/
COMMENT=	Flexible and intuitive table generator
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-pastel>=0.8<1:../../devel/ruby-pastel
DEPENDS+=	${RUBY_PKGPREFIX}-strings>=0.2.0<0.3:../../textproc/ruby-strings
DEPENDS+=	${RUBY_PKGPREFIX}-tty-screen>=0.8<1:../../devel/ruby-tty-screen

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
