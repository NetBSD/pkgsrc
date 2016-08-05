# $NetBSD: Makefile,v 1.2 2016/08/05 15:58:32 tsutsui Exp $

DISTNAME=	delayer-deferred-1.0.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/toshia/delayer-deferred
COMMENT=	Deferred for Delayer
LICENSE=	mit

DEPENDS+=       ${RUBY_PKGPREFIX}-delayer>=0.0.2<0.1:../../devel/ruby-delayer

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
