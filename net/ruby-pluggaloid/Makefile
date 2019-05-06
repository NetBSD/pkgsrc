# $NetBSD: Makefile,v 1.3 2019/05/06 04:36:17 tsutsui Exp $

DISTNAME=	pluggaloid-1.1.2
CATEGORIES=	net

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/toshia/pluggaloid
COMMENT=	Extensible plugin system for mikutter
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-delayer-[0-9]*:../../devel/ruby-delayer
DEPENDS+=	${RUBY_PKGPREFIX}-instance_storage>=1.0.0<2.0.0:../../devel/ruby-instance_storage

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
