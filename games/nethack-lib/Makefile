# $NetBSD: Makefile,v 1.16 2004/04/15 21:29:16 snj Exp $
#

.include		"../nethack-lib/Makefile.common"

PKGNAME=		nethack-lib-${NETHACK_VERSION}

COMMENT=		Data files for Nethack

USE_BUILDLINK3=		yes
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./sys/unix/setup.sh
ALL_TARGET=		datastuff
INSTALL_TARGET=		manpages install-dat

USE_PKGINSTALL=		yes

SUPPORT_FILES_PERMS+=	/dev/null ${PREFIX}/share/${NETHACK_DIR}/record \
			${ROOT_USER} games 664
SUPPORT_FILES_PERMS+=	/dev/null ${PREFIX}/share/${NETHACK_DIR}/logfile \
			${ROOT_USER} games 664

MAKE_DIRS_PERMS+=	${PREFIX}/share/${NETHACK_DIR}			\
			${ROOT_USER} games 775
MAKE_DIRS_PERMS+=	${PREFIX}/share/${NETHACK_DIR}/save		\
			${ROOT_USER} games 770

.include "../../mk/bsd.pkg.mk"
