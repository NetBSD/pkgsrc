# $NetBSD: Makefile,v 1.3 2021/01/11 13:26:44 taca Exp $

DISTNAME=	tty-reader-0.9.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ttytoolkit.org/
COMMENT=	Set of methods for processing keyboard input
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-wisper>=2.0<3:../../devel/ruby-wisper
DEPENDS+=	${RUBY_PKGPREFIX}-tty-screen>=0.8<1:../../devel/ruby-tty-screen
DEPENDS+=	${RUBY_PKGPREFIX}-tty-cursor>=0.7<1:../../devel/ruby-tty-cursor

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
