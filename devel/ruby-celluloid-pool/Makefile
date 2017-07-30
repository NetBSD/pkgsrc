# $NetBSD: Makefile,v 1.3 2017/07/30 22:32:17 wiz Exp $

DISTNAME=	celluloid-pool-0.20.5
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/celluloid/celluloid-pool
COMMENT=	Implementation of an actor pool based on the Celluloid framework
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-timers>=4.1.1:../../time/ruby-timers

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
