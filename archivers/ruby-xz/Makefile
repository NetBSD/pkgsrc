# $NetBSD: Makefile,v 1.14 2018/09/23 13:44:11 taca Exp $

DISTNAME=	ruby-xz-1.0.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
CATEGORIES=	archivers

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/Quintus/ruby-xz
COMMENT=	Ruby bindings for liblzma
LICENSE=	mit

DEPENDS+=	${RUBY_NAME}-fiddle>=${RUBY_VERSION}:../../devel/ruby-fiddle

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	lib/xz/lib_lzma.rb
SUBST_SED.path+=	-e "s,@LOCALBASE@,${LOCALBASE},g"
SUBST_SED.path+=	-e "s,@SHLIB_EXT@,${RUBY_SLEXT},g"

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
