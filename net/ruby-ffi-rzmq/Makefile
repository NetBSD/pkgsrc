# $NetBSD: Makefile,v 1.1 2020/09/20 08:45:49 ryoon Exp $

DISTNAME=	ffi-rzmq-2.0.7
CATEGORIES=	net

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/chuckremes/ffi-rzmq
COMMENT=	FFI bindings for ZeroMQ
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-ffi-rzmq-core>=1.0.7:../../net/ruby-ffi-rzmq-core

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
