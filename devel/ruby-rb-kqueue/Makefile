# $NetBSD: Makefile,v 1.2 2017/06/04 16:11:29 taca Exp $

DISTNAME=	rb-kqueue-0.2.5
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mat813/rb-kqueue
COMMENT=	Ruby wrapper for BSD's kqueue, using FFI
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-ffi>=0.5.0:../../devel/ruby-ffi

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
