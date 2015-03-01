# $NetBSD: Makefile,v 1.10 2015/03/01 12:58:16 taca Exp $

DISTNAME=	ruby-xz-0.2.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
CATEGORIES=	archivers

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/Quintus/ruby-xz
COMMENT=	Ruby bindings for liblzma
LICENSE=	mit

DEPENDS+=	xz-[0-9]*:../../archivers/xz
DEPENDS+=	${RUBY_PKGPREFIX}-ffi-[0-9]*:../../devel/ruby-ffi
DEPENDS+=	${RUBY_PKGPREFIX}-io-like-[0-9]*:../../devel/ruby-io-like

RUBY_VERSION_SUPPORTED= 193 200 21

EVAL_PREFIX+=	XZ_PREFIX=xz

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	lib/xz/lib_lzma.rb
SUBST_SED.path=		-e "s,@LOCALBASE@,${XZ_PREFIX},g"
SUBST_SED.path+=	-e "s,@SHLIB_EXT@,${RUBY_SLEXT},g"

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
