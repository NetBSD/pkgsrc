# $NetBSD: Makefile,v 1.6 2021/01/10 14:39:23 taca Exp $

DISTNAME=	celluloid-0.18.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/celluloid/celluloid
COMMENT=	Actor-based concurrent object framework for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-timers>=4.1.1:../../time/ruby-timers

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
