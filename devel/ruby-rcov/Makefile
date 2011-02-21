# $NetBSD: Makefile,v 1.5 2011/02/21 16:01:15 taca Exp $

DISTNAME=	rcov-0.9.9
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/relevance/rcov
COMMENT=	code coverage analysis for Ruby
LICENSE=	gnu-gpl-v2 OR ruby-license

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/rcov ${DESTDIR}${PREFIX}/bin/rcov${RUBY_VER}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
