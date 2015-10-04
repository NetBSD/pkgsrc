# $NetBSD: Makefile,v 1.3 2015/10/04 12:01:18 taca Exp $

DISTNAME=	celluloid-essentials-0.20.5
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/celluloid/celluloid-essentials
COMMENT=	Superstructural dependencies of Celluloid
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-timers>=4.1.1:../../time/ruby-timers

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
