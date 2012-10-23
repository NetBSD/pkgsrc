# $NetBSD: Makefile,v 1.8 2012/10/23 18:16:49 asau Exp $
#

PKGNAME=	${DISTNAME:S/crudesaml-/pam-saml-/}
PKGREVISION=	5
COMMENT=	Crude SAML assertion validator for bridging WebSSO and PAM

INSTALLATION_DIRS=	lib/security ${PKGMANDIR}/man5

do-install:
	cd ${WRKSRC} && ${SHLIBTOOL} --mode=install \
		${INSTALL_PROGRAM} pam_saml.la ${DESTDIR}${PREFIX}/lib/security
	${INSTALL_MAN} ${WRKSRC}/pam_saml.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5

.include "../../security/crudesaml/Makefile.common"
