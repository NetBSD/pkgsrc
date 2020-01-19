# $NetBSD: Makefile,v 1.1 2020/01/19 14:46:25 taca Exp $

DISTNAME=	tty-box-0.5.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://piotrmurach.github.io/tty
COMMENT=	Draw various frames and boxes in terminal interface
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-pastel>=0.7.2<0.8:../../devel/ruby-pastel
DEPENDS+=	${RUBY_PKGPREFIX}-tty-cursor>=0.7<1:../../devel/ruby-tty-cursor
DEPENDS+=	${RUBY_PKGPREFIX}-strings>=0.1.6<0.2:../../textproc/ruby-strings

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
