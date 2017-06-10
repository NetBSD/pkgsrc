# $NetBSD: Makefile,v 1.3 2017/06/10 07:55:56 tsutsui Exp $

DISTNAME=	delayer-deferred-2.0.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/toshia/delayer-deferred
COMMENT=	Deferred for Delayer
LICENSE=	mit

DEPENDS+=       ${RUBY_PKGPREFIX}-delayer>=0.0.2<0.1:../../devel/ruby-delayer

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
