# $NetBSD: Makefile,v 1.13 2001/09/22 11:06:13 wiz Exp $
#

DISTNAME=	popa3d-0.4.9.4
PKGNAME=	${DISTNAME}nb1
CATEGORIES=	mail
MASTER_SITES=	http://www.openwall.com/popa3d/ \
		ftp://ftp.openwall.com/pub/projects/popa3d/ \
		ftp://ftp.false.com/pub/security/popa3d/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.openwall.com/popa3d/
COMMENT=	secure, reliable, performant, and small pop3 server

.if exists(/usr/sbin/user)
USER_CMD=	/usr/sbin/user
GROUP_CMD=	/usr/sbin/group
.else
DEPENDS+=	user>=20000313:../../sysutils/user
USER_CMD=	${LOCALBASE}/sbin/user
GROUP_CMD=	${LOCALBASE}/sbin/group
.endif

post-patch:
	cd ${WRKSRC} && \
		${SED} "s,/usr/share/empty,${PREFIX}/share/empty," \
			params.h > params.h.new && \
		${MV} params.h.new params.h

do-install:
	@if `${GROUP_CMD} info -e popa3d`; then \
		${ECHO} Group \'popa3d\' already exists.; \
	else \
		${GROUP_CMD} add popa3d; \
	fi
	@if `${USER_CMD} info -e popa3d`; then \
		${ECHO} User \'popa3d\' already exists.; \
	else \
		${USER_CMD} add -g popa3d -d /nonexistent -s /sbin/nologin \
			popa3d; \
	fi
	${INSTALL_PROGRAM} -o popa3d -g popa3d -m 700 ${WRKSRC}/popa3d \
		${PREFIX}/libexec
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/popa3d
	cd ${WRKSRC} && ${INSTALL_DATA} DESIGN INSTALL LICENSE \
		${PREFIX}/share/doc/popa3d
	${INSTALL_DATA_DIR} ${PREFIX}/share/empty

.include "../../mk/bsd.pkg.mk"
