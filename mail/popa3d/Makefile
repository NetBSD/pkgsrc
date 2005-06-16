# $NetBSD: Makefile,v 1.41 2005/06/16 06:58:03 jlam Exp $
#

DISTNAME=	popa3d-1.0
CATEGORIES=	mail
MASTER_SITES=	http://www.openwall.com/popa3d/ \
		ftp://ftp.openwall.com/pub/projects/popa3d/ \
		ftp://ftp.false.com/pub/security/popa3d/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.openwall.com/popa3d/
COMMENT=	Secure, reliable, performant, and small pop3 server

POPA3D_USER?=	popa3d
POPA3D_GROUP?=	popa3d

PKG_GROUPS=	${POPA3D_GROUP}
PKG_USERS=	${POPA3D_USER}:${POPA3D_GROUP}

USE_PKGINSTALL=	YES

DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL

RCD_SCRIPTS=	popa3d

FILES_SUBST+=	POPA3D_USER=${POPA3D_USER}
FILES_SUBST+=	POPA3D_GROUP=${POPA3D_GROUP}

SUBST_CLASSES+=		params
SUBST_STAGE.params=	post-patch
SUBST_FILES.params=	params.h
SUBST_SED.params=	-e 's,/var/empty,${PREFIX}/share/empty,'	\
			-e 's,@@POPA3D_USER@@,"${POPA3D_USER}",'

INSTALLATION_DIRS=	man/man8 sbin

do-install:
	${INSTALL_PROGRAM} -m 500 ${WRKSRC}/popa3d ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/popa3d.8 ${PREFIX}/man/man8/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/popa3d
	cd ${WRKSRC} && ${INSTALL_DATA} DESIGN INSTALL LICENSE \
		${PREFIX}/share/doc/popa3d
	${INSTALL_DATA_DIR} ${PREFIX}/share/empty

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
