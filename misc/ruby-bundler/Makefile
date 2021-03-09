# $NetBSD: Makefile,v 1.43 2021/03/09 14:00:36 taca Exp $

DISTNAME=	bundler-2.2.14
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bundler.io/
COMMENT=	Manage your application's dependencies
LICENSE=	mit

RUBYGEM_OPTIONS+=	--format-executable
COMMANDS=		bundle bundler
USE_LANGUAGES=		# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	for f in ${COMMANDS}; do \
		${TEST} -f $${f}2-${RUBY_SUFFIX} || \
			${MV} $${f}${RUBY_SUFFIX} $${f}2-${RUBY_SUFFIX}; \
	done

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
