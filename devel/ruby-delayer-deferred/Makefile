# $NetBSD: Makefile,v 1.1 2016/01/09 18:44:08 tsutsui Exp $

DISTNAME=	delayer-deferred-1.0.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/toshia/delayer-deferred
COMMENT=	Deferred for Delayer
LICENSE=	mit

DEPENDS+=       ${RUBY_PKGPREFIX}-delayer>=0.0.2<0.1:../../devel/ruby-delayer

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
