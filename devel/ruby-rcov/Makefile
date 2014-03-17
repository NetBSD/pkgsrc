# $NetBSD: Makefile,v 1.10 2014/03/17 14:07:06 taca Exp $

DISTNAME=	rcov-1.0.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/relevance/rcov
COMMENT=	Code coverage analysis for Ruby
LICENSE=	gnu-gpl-v2 OR ruby-license

RUBY_VERSION_SUPPORTED=	18

USE_GCC_RUNTIME=	yes

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/rcov ${DESTDIR}${PREFIX}/bin/rcov${RUBY_SUFFIX}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
