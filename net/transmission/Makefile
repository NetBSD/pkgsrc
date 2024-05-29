# $NetBSD: Makefile,v 1.43 2024/05/29 16:34:04 adam Exp $

DEPENDS+=	transmission-common>=${VERSION}:../../net/transmission-common

CONFLICTS+=	Transmission-[0-9]*

RCD_SCRIPTS=		transmission

BUILD_DEFS+=		VARBASE

PKGREVISION= 2
.include "../../mk/bsd.prefs.mk"

TRANSMISSION_USER?=	transmission
TRANSMISSION_GROUP?=	transmission

FILES_SUBST+=		TRANSMISSION_USER=${TRANSMISSION_USER}
FILES_SUBST+=		TRANSMISSION_GROUP=${TRANSMISSION_GROUP}

PKG_USERS_VARS+=	TRANSMISSION_USER
PKG_GROUPS_VARS+=	TRANSMISSION_GROUP

PKG_GROUPS=		${TRANSMISSION_GROUP}
PKG_USERS=		${TRANSMISSION_USER}:${TRANSMISSION_GROUP}

OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/transmission \
			${TRANSMISSION_USER} ${TRANSMISSION_GROUP} 0755
OWN_DIRS_PERMS+=	${VARBASE}/log/transmission \
			${TRANSMISSION_USER} ${TRANSMISSION_GROUP} 0755

# https://github.com/transmission/transmission/issues/4864
post-install:
	${RM} -R ${DESTDIR}${PREFIX}/share/transmission/public_html

.include "../../net/transmission/Makefile.common"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
