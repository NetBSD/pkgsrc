# $NetBSD: Makefile,v 1.5 2020/01/26 17:32:06 rillig Exp $
#

DISTNAME=	passwdqc-1.1.4
PKGNAME=	pam-passwdqc-1.1.4
CATEGORIES=	security
MASTER_SITES=	http://www.openwall.com/passwdqc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.openwall.com/passwdqc/
COMMENT=	Password strength checker
#LICENSE=	# TODO: (see mk/license.mk)

BUILD_TARGET=		pam
INSTALLATION_DIRS=	lib/security ${PKGMANDIR}/man8 ${PKGMANDIR}/man5
CFLAGS+=		-DNO_STATIC_MODULES

do-install:
	${INSTALL_DATA} ${WRKSRC}/libpasswdqc.so ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/pam_passwdqc.so \
		${DESTDIR}${PREFIX}/lib/security
	${INSTALL_DATA} ${WRKSRC}/pam_passwdqc.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/passwdqc.conf.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
