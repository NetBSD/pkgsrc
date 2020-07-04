# $NetBSD: Makefile,v 1.5 2020/07/04 06:46:26 tsutsui Exp $

DISTNAME=	pluggaloid-1.5.0
CATEGORIES=	net

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/toshia/pluggaloid
COMMENT=	Extensible plugin system for mikutter
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-delayer>=1.0.0<2.0:../../devel/ruby-delayer
DEPENDS+=	${RUBY_PKGPREFIX}-instance_storage>=1.0.0<2.0.0:../../devel/ruby-instance_storage

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
