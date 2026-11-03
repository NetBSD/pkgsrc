# $NetBSD: Makefile,v 1.7 2026/11/03 15:49:20 taca Exp $

DISTNAME=	ffi-compiler-1.4.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ffi/ffi-compiler
COMMENT=	Ruby FFI Rakefile generator
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-ffi>=1.15.5:../../devel/ruby-ffi

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
