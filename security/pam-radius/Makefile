# $NetBSD: Makefile,v 1.6 2015/09/26 20:58:06 bsiegert Exp $

PKGNAME=	${DISTNAME:S/_/-/}
DISTNAME=	pam_radius-1.4.0
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.freeradius.org/pub/freeradius/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freeradius.org/pam_radius_auth/
COMMENT=	PAM module for authentication against a RADIUS server

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
EXTRACT_USING=	bsdtar

INSTALLATION_DIRS=	lib/security share/doc/pam-radius share/examples/pam-radius

do-install:
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${PREFIX}/share/doc/pam-radius
	${INSTALL_DATA} ${WRKSRC}/README.rst ${DESTDIR}${PREFIX}/share/doc/pam-radius
	${INSTALL_DATA} ${WRKSRC}/USAGE ${DESTDIR}${PREFIX}/share/doc/pam-radius
	${INSTALL_DATA} ${WRKSRC}/pam_radius_auth.conf \
		${DESTDIR}${PREFIX}/share/examples/pam-radius
	${INSTALL_LIB} ${WRKSRC}/pam_radius_auth.so ${DESTDIR}${PREFIX}/lib/security

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
