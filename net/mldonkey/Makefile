# $NetBSD: Makefile,v 1.34 2006/01/24 15:21:22 jmmv Exp $
#

.include "Makefile.common"

PKGREVISION=		1

RCD_SCRIPTS=		mldonkey

BUILD_DEFS+=		MLDONKEY_GROUP MLDONKEY_HOME MLDONKEY_USER

OWN_DIRS_PERMS=		${MLDONKEY_HOME} ${MLDONKEY_USER} ${MLDONKEY_GROUP} 0700

PKG_GROUPS=		${MLDONKEY_GROUP}
PKG_USERS=		${MLDONKEY_USER}:${MLDONKEY_GROUP}::Dedicated\ mldonkey\ server:${MLDONKEY_HOME}:${SH}

FILES_SUBST+=		MLDONKEY_GROUP=${MLDONKEY_GROUP:Q}
FILES_SUBST+=		MLDONKEY_HOME=${MLDONKEY_HOME:Q}
FILES_SUBST+=		MLDONKEY_USER=${MLDONKEY_USER:Q}

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/libexec/mldonkey
	${INSTALL_PROGRAM} ${WRKSRC}/mlnet ${PREFIX}/libexec/mldonkey

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
