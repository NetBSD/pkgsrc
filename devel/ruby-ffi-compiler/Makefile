# $NetBSD: Makefile,v 1.2 2020/01/18 23:30:40 rillig Exp $

DISTNAME=	ffi-compiler-1.0.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.github.com/ffi/ffi
COMMENT=	Ruby FFI Rakefile generator
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-ffi>=1.0.0:../../devel/ruby-ffi

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
