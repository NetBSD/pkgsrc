# $NetBSD: Makefile,v 1.19 2001/12/09 22:06:45 wiz Exp $
#

DISTNAME=	popa3d-0.4.9.4
PKGREVISION=	2
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

FILES_SUBST+=	POPA3D_USER=${POPA3D_USER}
FILES_SUBST+=	POPA3D_GROUP=${POPA3D_GROUP}

post-patch:
	cd ${WRKSRC} && \
		${SED} "s,/usr/share/empty,${PREFIX}/share/empty," \
			params.h > params.h.new && \
		${MV} params.h.new params.h

do-install:
	${INSTALL_PROGRAM} -m 700 ${WRKSRC}/popa3d ${PREFIX}/libexec
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/popa3d
	cd ${WRKSRC} && ${INSTALL_DATA} DESIGN INSTALL LICENSE \
		${PREFIX}/share/doc/popa3d
	${INSTALL_DATA_DIR} ${PREFIX}/share/empty

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
