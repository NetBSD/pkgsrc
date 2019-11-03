# $NetBSD: Makefile,v 1.6 2019/11/03 10:00:23 rillig Exp $

DISTNAME=	delayer-deferred-2.1.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/toshia/delayer-deferred
COMMENT=	Deferred for Delayer
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-delayer>=1.0<2.0:../../devel/ruby-delayer

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
