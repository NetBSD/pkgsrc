# $NetBSD: Makefile,v 1.3 2021/01/11 13:23:41 taca Exp $

DISTNAME=	tty-box-0.7.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ttytoolkit.org/
COMMENT=	Draw various frames and boxes in terminal interface
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-pastel>=0.8<1:../../devel/ruby-pastel
DEPENDS+=	${RUBY_PKGPREFIX}-tty-cursor>=0.7<1:../../devel/ruby-tty-cursor
DEPENDS+=	${RUBY_PKGPREFIX}-strings>=0.2.0<0.3:../../textproc/ruby-strings

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
