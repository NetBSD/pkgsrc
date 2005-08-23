# $NetBSD: Makefile,v 1.29 2005/08/23 11:48:50 rillig Exp $
#

.include "Makefile.common"

USE_PKGINSTALL=		YES

CONFIGURE_ARGS+=	--disable-gui

RCD_SCRIPTS=		mldonkey

BUILD_DEFS+=		MLDONKEY_GROUP MLDONKEY_HOME MLDONKEY_USER

OWN_DIRS_PERMS=		${MLDONKEY_HOME} ${MLDONKEY_USER} ${MLDONKEY_GROUP} 0700

PKG_GROUPS=		${MLDONKEY_GROUP}
PKG_USERS=		${MLDONKEY_USER}:${MLDONKEY_GROUP}::Dedicated\ mldonkey\ server:${MLDONKEY_HOME}:${SH}

FILES_SUBST+=		MLDONKEY_GROUP="${MLDONKEY_GROUP}"
FILES_SUBST+=		MLDONKEY_HOME="${MLDONKEY_HOME}"
FILES_SUBST+=		MLDONKEY_USER="${MLDONKEY_USER}"

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/libexec/mldonkey
	${INSTALL_PROGRAM} ${WRKSRC}/mlnet ${PREFIX}/libexec/mldonkey

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
