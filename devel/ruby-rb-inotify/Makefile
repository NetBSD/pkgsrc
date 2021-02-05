# $NetBSD: Makefile,v 1.3 2021/02/05 17:06:55 taca Exp $

DISTNAME=	rb-inotify-0.10.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nex3/rb-inotify
COMMENT=	Ruby wrapper for Linux's inotify, using FFI
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-ffi>=0.5.0:../../devel/ruby-ffi

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
