# $NetBSD: Makefile,v 1.5 2005/12/05 20:50:09 rillig Exp $
#

.include "../../editors/ce/Makefile.common"

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
