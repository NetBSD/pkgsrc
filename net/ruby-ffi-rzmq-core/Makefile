# $NetBSD: Makefile,v 1.2 2020/09/20 15:44:04 taca Exp $

DISTNAME=	ffi-rzmq-core-1.0.7
CATEGORIES=	net

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/chuckremes/ffi-rzmq-core
COMMENT=	FFI wrapper around the zeromq libzmq C API
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-ffi-[0-9]*:../../devel/ruby-ffi

USE_LANGUAGES=	# none

.include "../../net/zeromq/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
