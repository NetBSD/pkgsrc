# $NetBSD: Makefile,v 1.1 2015/03/13 15:58:33 taca Exp $

DISTNAME=	rb-inotify-0.9.5
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/nex3/rb-inotify
COMMENT=	Ruby wrapper for Linux's inotify, using FFI
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-ffi>=0.5.0:../../devel/ruby-ffi

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
