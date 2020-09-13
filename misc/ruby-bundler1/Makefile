# $NetBSD: Makefile,v 1.3 2020/09/13 14:57:04 taca Exp $

DISTNAME=	bundler-1.17.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/bundler/bundler1/}
PKGREVISION=	2
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bundler.io/
COMMENT=	Manage your application's dependencies
LICENSE=	mit

RUBYGEM_OPTIONS+=	--format-executable
COMMANDS=		bundle bundler

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	for f in ${COMMANDS}; do \
		${TEST} -f $${f}1-${RUBY_SUFFIX} || \
			${MV} $${f}${RUBY_SUFFIX} $${f}1-${RUBY_SUFFIX}; \
	done

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
