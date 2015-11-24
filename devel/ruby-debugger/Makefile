# $NetBSD: Makefile,v 1.6 2015/11/24 16:49:30 jperkin Exp $

DISTNAME=	debugger-1.6.8
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://github.com/cldwalker/debugger
COMMENT=	Fast Ruby debugger - base + cli
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-columnize>=0.3.1:../../misc/ruby-columnize
DEPENDS+=	${RUBY_PKGPREFIX}-debugger-ruby_core_source>=1.3.5<1.4:../../devel/ruby-debugger-ruby_core_source
DEPENDS+=	${RUBY_PKGPREFIX}-debugger-linecache>=1.2.0<1.3:../../devel/ruby-debugger-linecache

BUILDLINK_PASSTHRU_DIRS+= ${PREFIX}/${GEM_HOME}/gems

RUBY_VERSION_SUPPORTED=	200 21

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
