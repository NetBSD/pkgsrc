# $NetBSD: Makefile,v 1.1 2020/01/19 14:53:44 taca Exp $

DISTNAME=	tty-reader-0.7.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://piotrmurach.github.io/tty
COMMENT=	Set of methods for processing keyboard input
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-wisper>=2.0.0<2.1:../../devel/ruby-wisper
DEPENDS+=	${RUBY_PKGPREFIX}-tty-screen>=0.7<1:../../devel/ruby-tty-screen
DEPENDS+=	${RUBY_PKGPREFIX}-tty-cursor>=0.7<1:../../devel/ruby-tty-cursor

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
