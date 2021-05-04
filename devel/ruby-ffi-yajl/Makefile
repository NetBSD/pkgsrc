# $NetBSD: Makefile,v 1.11 2021/05/04 13:32:41 taca Exp $

DISTNAME=	ffi-yajl-2.4.0
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
