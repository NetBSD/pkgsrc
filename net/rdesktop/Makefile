# $NetBSD: Makefile,v 1.7 2003/02/13 23:25:05 grant Exp $
#

DISTNAME=		rdesktop-1.2.0
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rdesktop/}

MAINTAINER=		grant@netbsd.org
HOMEPAGE=		http://www.rdesktop.org/
COMMENT=		Open-source Remote Desktop Protocol client

USE_GMAKE=		YES
USE_BUILDLINK2=		YES
NO_CONFIGURE=		YES
CONFIGURE_ARGS=		--prefix=${LOCALBASE}

ALL_TARGET=		rdesktop

USE_X11=		YES

DATADIR=		${PREFIX}/share/rdesktop
KEYMAP_PATH=		${DATADIR}/keymaps

CFLAGS+=		-DWITH_OPENSSL
CFLAGS+=		-DKEYMAP_PATH=\\\"${KEYMAP_PATH}\\\"
LDFLAGS+=		-lX11 -lcrypto

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LDFLAGS+=	-lnsl -lsocket
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rdesktop ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/rdesktop.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${DATADIR}
	${INSTALL_DATA_DIR} ${KEYMAP_PATH}
	${INSTALL_DATA} ${WRKSRC}/keymaps/?? ${KEYMAP_PATH}
	${INSTALL_DATA} ${WRKSRC}/keymaps/??-?? ${KEYMAP_PATH}
	${INSTALL_DATA} ${WRKSRC}/keymaps/common ${KEYMAP_PATH}
	${INSTALL_DATA} ${WRKSRC}/keymaps/modifiers ${KEYMAP_PATH}

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
