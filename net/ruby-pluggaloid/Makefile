# $NetBSD: Makefile,v 1.4 2019/06/16 16:12:12 tsutsui Exp $

DISTNAME=	pluggaloid-1.2.0
CATEGORIES=	net

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/toshia/pluggaloid
COMMENT=	Extensible plugin system for mikutter
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-delayer>=1.0.0<2.0:../../devel/ruby-delayer
DEPENDS+=	${RUBY_PKGPREFIX}-instance_storage>=1.0.0<2.0.0:../../devel/ruby-instance_storage

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
