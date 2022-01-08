# $NetBSD: Makefile,v 1.7 2022/01/08 15:15:22 tsutsui Exp $

DISTNAME=	pluggaloid-1.7.0
CATEGORIES=	net

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/toshia/pluggaloid
COMMENT=	Extensible plugin system for mikutter
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-delayer>=1.1.0<2.0:../../devel/ruby-delayer
DEPENDS+=	${RUBY_PKGPREFIX}-instance_storage>=1.0.0<2.0.0:../../devel/ruby-instance_storage

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
