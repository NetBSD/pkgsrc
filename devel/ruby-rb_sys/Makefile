# $NetBSD: Makefile,v 1.2 2026/01/17 16:35:47 taca Exp $

DISTNAME=	rb_sys-0.9.124
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://oxidize-rb.github.io/rb-sys/
COMMENT=	Helpers for compiling Rust extensions for ruby
LICENSE=	mit

OVERRIDE_GEMSPEC+=	rake-compiler-dock>=1.11.0

DEPENDS+=	${RUBY_PKGPREFIX}-rake-compiler-dock>=1.11.0<1.12:../../devel/ruby-rake-compiler-dock

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
