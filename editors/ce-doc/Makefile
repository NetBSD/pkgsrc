# $NetBSD: Makefile,v 1.2 2004/07/28 17:24:59 schmonz Exp $
#

.include "../ce/Makefile.common"

PKGNAME=		ce-doc-${VERSION}
COMMENT+=		, documentation

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_BUILD=		# defined

INSTALL_TARGET=		doc-install

INSTALLATION_DIRS=	bin share/doc/ce

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	teach-ce
SUBST_SED.paths=	-e 's|@LN@|${LN}|g' -e 's|@PREFIX@|${PREFIX}|g'
SUBST_SED.paths+=	-e 's|@LOCALBASE@|${LOCALBASE}|g'

.include "../../mk/bsd.pkg.mk"
