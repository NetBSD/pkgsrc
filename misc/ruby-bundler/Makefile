# $NetBSD: Makefile,v 1.54 2022/03/06 09:03:06 taca Exp $

DISTNAME=	bundler-2.3.8
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
