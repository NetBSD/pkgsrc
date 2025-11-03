# $NetBSD: Makefile,v 1.1 2025/11/03 05:38:50 taca Exp $

DISTNAME=	rb_sys-0.9.117
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://oxidize-rb.github.io/rb-sys/
COMMENT=	Helpers for compiling Rust extensions for ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rake-compiler-dock>=1.9.1<1.10:../../devel/ruby-rake-compiler-dock

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
