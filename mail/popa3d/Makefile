# $NetBSD: Makefile,v 1.20 2001/12/23 23:03:22 wiz Exp $
#

DISTNAME=	popa3d-0.5
CATEGORIES=	mail
MASTER_SITES=	http://www.openwall.com/popa3d/ \
		ftp://ftp.openwall.com/pub/projects/popa3d/ \
		ftp://ftp.false.com/pub/security/popa3d/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.openwall.com/popa3d/
COMMENT=	secure, reliable, performant, and small pop3 server

POPA3D_USER?=	popa3d
POPA3D_GROUP?=	popa3d

PKG_GROUPS=	${POPA3D_GROUP}
PKG_USERS=	${POPA3D_USER}:${POPA3D_GROUP}

DEINSTALL_EXTRA_TMPL=	${PKGDIR}/DEINSTALL
USE_BUILDLINK_ONLY=	# defined

FILES_SUBST+=	POPA3D_USER=${POPA3D_USER}
FILES_SUBST+=	POPA3D_GROUP=${POPA3D_GROUP}

post-patch:
	cd ${WRKSRC} && \
		${SED} "s,/var/empty,${PREFIX}/share/empty," \
			params.h > params.h.new && \
		${MV} params.h.new params.h

do-install:
	${INSTALL_PROGRAM} -m 500 ${WRKSRC}/popa3d ${PREFIX}/libexec
	${INSTALL_DATA} -m 644 ${WRKSRC}/popa3d.8 ${PREFIX}/man/man8/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/popa3d
	cd ${WRKSRC} && ${INSTALL_DATA} DESIGN INSTALL LICENSE \
		${PREFIX}/share/doc/popa3d
	${INSTALL_DATA_DIR} ${PREFIX}/share/empty

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
