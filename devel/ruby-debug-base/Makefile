# $NetBSD: Makefile,v 1.9 2014/03/13 11:08:51 jperkin Exp $

DISTNAME=	ruby-debug-base-0.10.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/ruby-debug/
COMMENT=	Fast implementation of the standard Ruby debugger
LICENSE=	2-clause-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-linecache>=0.3:../../devel/ruby-linecache

RUBY_VERSION_SUPPORTED= 18

OVERRIDE_GEMSPEC=	:files ext/win32/Makefile= ext/win32/breakpoint.o= \
	ext/win32/ruby_debug.o= ext/win32/ruby_debug.so=

USE_GCC_RUNTIME=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
