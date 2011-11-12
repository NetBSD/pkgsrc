# $NetBSD: Makefile,v 1.6 2011/11/12 15:04:58 taca Exp $

DISTNAME=	ruby-xz-0.0.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
CATEGORIES=	archivers

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/Quintus/ruby-xz
COMMENT=	Ruby bindings for liblzma
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	xz-[0-9]*:../../archivers/xz
DEPENDS+=	${RUBY_PKGPREFIX}-ffi-[0-9]*:../../devel/ruby-ffi

RUBY_VERSION_SUPPORTED=	19 193
RUBYGEMS_REQD=		1.8.10

PRIVILEGED_STAGES+=	clean

EVAL_PREFIX+=	XZ_PREFIX=xz

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	lib/xz.rb
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
