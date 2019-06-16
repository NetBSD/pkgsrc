# $NetBSD: Makefile,v 1.4 2019/06/16 16:07:14 tsutsui Exp $

DISTNAME=	delayer-deferred-2.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/toshia/delayer-deferred
COMMENT=	Deferred for Delayer
LICENSE=	mit

DEPENDS+=       ${RUBY_PKGPREFIX}-delayer>=1.0<2.0:../../devel/ruby-delayer

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
