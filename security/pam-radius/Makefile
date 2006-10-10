# $NetBSD: Makefile,v 1.1.1.1 2006/10/10 14:38:01 adrianp Exp $

PKGNAME=	${DISTNAME:S/_/-/}
DISTNAME=	pam_radius-1.3.16
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.freeradius.org/pub/radius/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.freeradius.org/pam_radius_auth/
COMMENT=	PAM module for authentication against a RADIUS server

NO_CONFIGURE=	YES
EXTRACT_SUFX=	.tar

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pam-radius
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/pam-radius
	${INSTALL_DATA_DIR} ${PREFIX}/lib/security

	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/pam-radius
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/pam-radius
	${INSTALL_DATA} ${WRKSRC}/USAGE ${PREFIX}/share/doc/pam-radius
	${INSTALL_DATA} ${WRKSRC}/pam_radius_auth.conf \
		${PREFIX}/share/examples/pam-radius
	${INSTALL_LIB} ${WRKSRC}/pam_radius_auth.so ${PREFIX}/lib/security

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
