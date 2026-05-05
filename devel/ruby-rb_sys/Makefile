# $NetBSD: Makefile,v 1.4 2026/05/05 12:47:02 taca Exp $

DISTNAME=	rb_sys-0.9.128
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://oxidize-rb.github.io/rb-sys/
COMMENT=	Helpers for compiling Rust extensions for ruby
LICENSE=	mit

OVERRIDE_GEMSPEC+=	rake-compiler-dock>=1.12.0

DEPENDS+=	${RUBY_PKGPREFIX}-rake-compiler-dock>=1.12.0<1.13:../../devel/ruby-rake-compiler-dock

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
