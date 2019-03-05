# $NetBSD: Makefile,v 1.1 2019/03/05 07:46:47 taca Exp $

DISTNAME=	bundler-1.17.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/bundler/bundler1/}
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bundler.io/
COMMENT=	Manage your application's dependencies
LICENSE=	mit

RUBYGEM_OPTIONS+=	--format-executable
COMMANDS=		bundle bundler

.for f in ${COMMANDS}
OVERRIDE_GEMSPEC+=	:executables ${f}=${f}1 :files exe/${f}=exe/${f}1
.endfor

pre-configure:
	for f in ${COMMANDS}; do \
		${TEST} -f ${WRKSRC}/exe/$${f}1 || \
		${MV} ${WRKSRC}/exe/$${f} ${WRKSRC}/exe/$${f}1; \
	done

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
