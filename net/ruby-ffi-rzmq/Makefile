# $NetBSD: Makefile,v 1.2 2020/09/20 15:44:04 taca Exp $

DISTNAME=	ffi-rzmq-2.0.7
CATEGORIES=	net

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/chuckremes/ffi-rzmq
COMMENT=	FFI bindings for ZeroMQ
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-ffi-rzmq-core>=1.0.7:../../net/ruby-ffi-rzmq-core

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
