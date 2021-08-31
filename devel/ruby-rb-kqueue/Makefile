# $NetBSD: Makefile,v 1.5 2021/08/31 15:17:06 taca Exp $

DISTNAME=	rb-kqueue-0.2.7
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mat813/rb-kqueue
COMMENT=	Ruby wrapper for BSD's kqueue, using FFI
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-ffi>=0.5.0:../../devel/ruby-ffi

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
