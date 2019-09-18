# $NetBSD: Makefile,v 1.2 2019/09/18 14:27:45 taca Exp $

DISTNAME=	bundler-1.17.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/bundler/bundler1/}
PKGREVISION=	1
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
