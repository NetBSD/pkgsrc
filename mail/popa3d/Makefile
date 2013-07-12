# $NetBSD: Makefile,v 1.53 2013/07/12 10:44:57 jperkin Exp $
#

DISTNAME=	popa3d-1.0.2
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.openwall.com/popa3d/ \
		ftp://ftp.openwall.com/pub/projects/popa3d/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openwall.com/popa3d/
COMMENT=	Secure, reliable, performant, and small pop3 server

POPA3D_USER?=	popa3d
POPA3D_GROUP?=	popa3d

PKG_GROUPS=	${POPA3D_GROUP}
PKG_USERS=	${POPA3D_USER}:${POPA3D_GROUP}

PKG_GROUPS_VARS+=	POPA3D_GROUP
PKG_USERS_VARS+=	POPA3D_USER

RCD_SCRIPTS=	popa3d

FILES_SUBST+=	POPA3D_USER=${POPA3D_USER:Q}
FILES_SUBST+=	POPA3D_GROUP=${POPA3D_GROUP:Q}

SUBST_CLASSES+=		params
SUBST_STAGE.params=	pre-configure
SUBST_FILES.params=	params.h
SUBST_SED.params=	-e 's,/var/empty,${PREFIX}/share/empty,'
SUBST_SED.params+=	-e 's,@@POPA3D_USER@@,"${POPA3D_USER}",'

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

do-install:
	${INSTALL_PROGRAM} -m 500 ${WRKSRC}/popa3d ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/popa3d.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/popa3d
	cd ${WRKSRC} && ${INSTALL_DATA} DESIGN INSTALL LICENSE \
		${DESTDIR}${PREFIX}/share/doc/popa3d
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/empty

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
