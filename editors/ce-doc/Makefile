# $NetBSD: Makefile,v 1.8 2006/10/03 05:30:04 rillig Exp $
#

.include "../../editors/ce/Makefile.common"

PKGNAME=		ce-doc-${VERSION}
PKGREVISION=		2
COMMENT+=		, documentation

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_BUILD=		yes
USE_LANGUAGES=		c

INSTALL_TARGET=		doc-install

INSTALLATION_DIRS=	bin share/doc/ce

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	teach-ce.in
SUBST_SED.paths=	-e 's|@LN@|${LN}|g'
SUBST_SED.paths+=	-e '1s,/bin/bash,'${SH:Q}','

.include "../../mk/bsd.pkg.mk"
