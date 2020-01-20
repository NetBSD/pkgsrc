# $NetBSD: Makefile,v 1.9 2020/01/20 15:33:37 taca Exp $

DISTNAME=	ffi-yajl-2.3.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chef/ffi-yajl
COMMENT=	Ruby FFI wrapper around YAJL 2.x
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-libyajl2>=1.2:../../devel/ruby-libyajl2

RUBYGEM_OPTIONS+=	--format-executable

.include "../../devel/yajl/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
