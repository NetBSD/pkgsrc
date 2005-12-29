# $NetBSD: Makefile,v 1.22 2005/12/29 06:21:41 jlam Exp $
#

.include		"../../games/nethack-lib/Makefile.common"

PKGNAME=		nethack-lib-${NETHACK_VERSION}
PKGREVISION=		1

COMMENT=		Data files for Nethack

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./sys/unix/setup.sh
BUILD_TARGET=		datastuff
INSTALL_TARGET=		manpages install-dat


CONF_FILES_PERMS+=	/dev/null ${PREFIX}/share/${NETHACK_DIR}/record \
			${ROOT_USER} games 664
CONF_FILES_PERMS+=	/dev/null ${PREFIX}/share/${NETHACK_DIR}/logfile \
			${ROOT_USER} games 664

REQD_DIRS_PERMS+=	${PREFIX}/share/${NETHACK_DIR}			\
			${ROOT_USER} games 775
REQD_DIRS_PERMS+=	${PREFIX}/share/${NETHACK_DIR}/save		\
			${ROOT_USER} games 770

.include "../../mk/bsd.pkg.mk"
