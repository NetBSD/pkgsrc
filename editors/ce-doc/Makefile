# $NetBSD: Makefile,v 1.4 2005/09/28 20:52:20 rillig Exp $
#

.include "../ce/Makefile.common"

PKGNAME=		ce-doc-${VERSION}
COMMENT+=		, documentation

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_BUILD=		yes

INSTALL_TARGET=		doc-install

INSTALLATION_DIRS=	bin share/doc/ce

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	teach-ce.in
SUBST_SED.paths=	-e 's|@LN@|${LN}|g'

.include "../../mk/bsd.pkg.mk"
