# $NetBSD: Makefile,v 1.26 2008/09/25 14:02:09 wiz Exp $
#

.include		"../../games/nethack-lib/Makefile.common"

PKGNAME=		nethack-lib-${NETHACK_VERSION}
PKGREVISION=		2

COMMENT=		Data files for Nethack

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./sys/unix/setup.sh
BUILD_TARGET=		datastuff
INSTALL_TARGET=		manpages install-dat
INSTALLATION_DIRS=	${PKGMANDIR}/man6

# Special handling for the scorefiles: we do not want to delete
# them between package installations and deinstallations.
#
# These should eventually migrate to a better location, but keep them
# here for now until we lose backward compatibility because of changes
# to the fileformat.
CONF_FILES_PERMS+=	/dev/null ${PREFIX}/share/${NETHACK_DIR}/record \
			${ROOT_USER} ${NETHACK_GROUP} 664
CONF_FILES_PERMS+=	/dev/null ${PREFIX}/share/${NETHACK_DIR}/logfile \
			${ROOT_USER} ${NETHACK_GROUP} 664

REQD_DIRS_PERMS+=	${PREFIX}/share/${NETHACK_DIR}			\
			${ROOT_USER} ${NETHACK_GROUP} 775
REQD_DIRS_PERMS+=	${PREFIX}/share/${NETHACK_DIR}/save		\
			${ROOT_USER} ${NETHACK_GROUP} 770

CHECK_FILES_SKIP+=	${PREFIX}/share/${NETHACK_DIR}/logfile		\
			${PREFIX}/share/${NETHACK_DIR}/record

.include "../../mk/bsd.pkg.mk"
