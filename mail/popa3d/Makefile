# $NetBSD: Makefile,v 1.15 2001/11/26 20:38:31 jlam Exp $
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

PKG_GROUPS=	popa3d
PKG_USERS=	popa3d:popa3d

INSTALL_EXTRA_TMPL=	${PKGDIR}/INSTALL
DEINSTALL_EXTRA_TMPL=	${PKGDIR}/DEINSTALL

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

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
