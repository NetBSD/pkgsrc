# $NetBSD: Makefile,v 1.12 2019/05/23 19:23:00 rillig Exp $
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
SUBST_VARS.paths=	LN
SUBST_SED.paths+=	-e '1s,/bin/bash,'${SH:Q}','

.include "../../mk/bsd.pkg.mk"
