# $NetBSD: Makefile,v 1.3 2017/03/20 15:21:49 taca Exp $

DISTNAME=	rb-inotify-0.9.8
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nex3/rb-inotify
COMMENT=	Ruby wrapper for Linux's inotify, using FFI
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-ffi>=0.5.0:../../devel/ruby-ffi

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
