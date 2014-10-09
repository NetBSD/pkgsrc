# $NetBSD: Makefile,v 1.11 2014/10/09 14:06:32 wiz Exp $
#

.include "../../editors/ce/Makefile.common"

PKGNAME=		ce-doc-${VERSION}
PKGREVISION=		2
COMMENT+=		, documentation

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
