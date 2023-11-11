# $NetBSD: Makefile,v 1.7 2023/11/11 09:30:54 taca Exp $

DISTNAME=	ffi-libarchive-1.1.13
CATEGORIES=	archivers

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chef/ffi-libarchive
COMMENT=	Ruby FFI binding to libarchive
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

DEPENDS+=	${RUBY_PKGPREFIX}-ffi>=1.0<2:../../devel/ruby-ffi

.include "../../lang/ruby/gem.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
