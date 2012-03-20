# $NetBSD: Makefile,v 1.8 2012/03/20 10:25:47 taca Exp $

DISTNAME=	rcov-1.0.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/relevance/rcov
COMMENT=	Code coverage analysis for Ruby
LICENSE=	gnu-gpl-v2 OR ruby-license

RUBY_VERSION_SUPPORTED=	18

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/rcov ${DESTDIR}${PREFIX}/bin/rcov${RUBY_VER}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
