# $NetBSD: Makefile,v 1.1 2015/01/19 20:46:23 fhajny Exp $

DISTNAME=	ffi-yajl-1.3.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/opscode/ffi-yajl
COMMENT=	Ruby FFI gem wrapper around yajl2 library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-ffi>=1.5:../../devel/ruby-ffi
DEPENDS+=	${RUBY_PKGPREFIX}-libyajl2>=1.2:../../devel/ruby-libyajl2

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
