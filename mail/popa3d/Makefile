# $NetBSD: Makefile,v 1.2 2000/04/03 02:12:27 wiz Exp $
#

DISTNAME=	popa3d-0.4
CATEGORIES=	mail
MASTER_SITES=	http://www.openwall.com/popa3d/ \
		ftp://ftp.openwall.com/popa3d/ \
		ftp://ftp.false.com/pub/security/popa3d/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.openwall.com/popa3d/

.if exists(/usr/sbin/user)
USER_CMD=	/usr/sbin/user
GROUP_CMD=	/usr/sbin/group
.else
DEPENDS+=	user>=20000313:../../sysutils/user
USER_CMD=	${LOCALBASE}/sbin/user
GROUP_CMD=	${LOCALBASE}/sbin/group
.endif

do-install:
	@if [ `${GROUP_CMD} info -e popa3d` ]; then \
		${GROUP_CMD} add popa3d; \
	else \
		${ECHO} Group \'popa3d\' already exists.; \
	fi
	@if [ `${USER_CMD} info -e popa3d` ]; then \
		${USER_CMD} add -g popa3d -d /nonexistent -s /sbin/nologin \
			popa3d; \
	else \
		${ECHO} User \'popa3d\' already exists.; \
	fi
	${INSTALL_PROGRAM} -o popa3d -g popa3d -m 700 ${WRKSRC}/popa3d \
		${PREFIX}/libexec
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/popa3d
	cd ${WRKSRC} && ${INSTALL_DATA} COPYING DESIGN INSTALL \
		${PREFIX}/share/doc/popa3d

.include "../../mk/bsd.pkg.mk"
