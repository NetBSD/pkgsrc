# $NetBSD: Makefile,v 1.8 2012/09/11 19:47:00 asau Exp $

DISTNAME=	ruby-xz-0.1.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
CATEGORIES=	archivers

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/Quintus/ruby-xz
COMMENT=	Ruby bindings for liblzma
LICENSE=	mit

DEPENDS+=	xz-[0-9]*:../../archivers/xz
DEPENDS+=	${RUBY_PKGPREFIX}-ffi-[0-9]*:../../devel/ruby-ffi
DEPENDS+=	${RUBY_PKGPREFIX}-io-like-[0-9]*:../../devel/ruby-io-like

RUBYGEMS_REQD=		1.8.10

PRIVILEGED_STAGES+=	clean

EVAL_PREFIX+=	XZ_PREFIX=xz

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	lib/xz/lib_lzma.rb
SUBST_SED.path=		-e "s,@LOCALBASE@,${XZ_PREFIX},g"
SUBST_SED.path+=	-e "s,@SHLIB_EXT@,${SHLIB_EXT},g"

.include "../../mk/bsd.prefs.mk"

.if ${_OPSYS_SHLIB_TYPE} == "dylib"
SHLIB_EXT=	dylib
.else
SHLIB_EXT=	so
.endif

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
