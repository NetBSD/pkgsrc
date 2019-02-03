# $NetBSD: Makefile,v 1.16 2019/02/03 13:45:06 taca Exp $

DISTNAME=	ruby-xz-1.0.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
CATEGORIES=	archivers

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/Quintus/ruby-xz
COMMENT=	Ruby bindings for liblzma
LICENSE=	mit

DEPENDS+=	${RUBY_NAME}-fiddle>=${RUBY_VERSION}:../../devel/ruby-fiddle

RUBY_VERSIONS_ACCEPTED=	23 24 25 26

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	lib/xz/lib_lzma.rb
SUBST_SED.path+=	-e "s,@LOCALBASE@,${LOCALBASE},g"
SUBST_SED.path+=	-e "s,@SHLIB_EXT@,${RUBY_SLEXT},g"

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
