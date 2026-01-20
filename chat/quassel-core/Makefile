# $NetBSD: Makefile,v 1.1 2026/01/20 16:06:42 kikadf Exp $

.include "../../chat/quassel/Makefile.common"

PKGNAME=	${DISTNAME:S/quassel/quassel-core/}
COMMENT=	Modern, cross-platform, distributed IRC client - core only

.include "../../mk/bsd.prefs.mk"
RCD_SCRIPTS=	quasselcore

.if ${INIT_SYSTEM} == "rc.d"
DEPENDS+=	daemonize-[0-9]*:../../sysutils/daemonize
.endif

QUASSELCORE_USER?=	quasselcore
QUASSELCORE_GROUP?=	quasselcore
PKG_GROUPS=		${QUASSELCORE_GROUP}
PKG_USERS=		${QUASSELCORE_USER}:${QUASSELCORE_GROUP}
PKG_GROUPS_VARS=	QUASSELCORE_GROUP
PKG_USERS_VARS=		QUASSELCORE_USER
FILES_SUBST+=		QUASSELCORE_USER=${QUASSELCORE_USER}
FILES_SUBST+=		QUASSELCORE_GROUP=${QUASSELCORE_GROUP}

CMAKE_CONFIGURE_ARGS+=	-DWANT_QTCLIENT=OFF
CMAKE_CONFIGURE_ARGS+=	-DWANT_MONO=OFF
CMAKE_CONFIGURE_ARGS+=	-DWANT_BUNDLED_ICONS=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_SHARED=OFF

post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/share/quassel

.include "../../mk/bsd.pkg.mk"
