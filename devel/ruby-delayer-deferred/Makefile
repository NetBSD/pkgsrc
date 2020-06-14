# $NetBSD: Makefile,v 1.8 2020/06/14 14:02:09 taca Exp $

DISTNAME=	delayer-deferred-2.2.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/toshia/delayer-deferred
COMMENT=	Deferred for Delayer
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-delayer>=1.1.2<2.0:../../devel/ruby-delayer

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
