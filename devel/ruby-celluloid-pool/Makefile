# $NetBSD: Makefile,v 1.2 2015/10/04 12:03:12 taca Exp $

DISTNAME=	celluloid-pool-0.20.5
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/celluloid/celluloid-pool
COMMENT=	Implementation of an actor pool based on the Celluloid framework
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-timers>=4.1.1:../../time/ruby-timers

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
