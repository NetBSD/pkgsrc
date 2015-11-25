# $NetBSD: Makefile,v 1.12 2015/11/25 12:47:32 jperkin Exp $

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

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	lib/xz/lib_lzma.rb
SUBST_SED.path+=	-e "s,@LOCALBASE@,${LOCALBASE},g"
SUBST_SED.path+=	-e "s,@SHLIB_EXT@,${RUBY_SLEXT},g"

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
