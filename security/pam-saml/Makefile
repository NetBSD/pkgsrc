# $NetBSD: Makefile,v 1.14 2017/05/25 03:17:41 manu Exp $
#

PKGNAME=	${DISTNAME:S/crudesaml-/pam-saml-/}
#PKGREVISION=	1
COMMENT=	Crude SAML assertion validator for bridging WebSSO and PAM

INSTALLATION_DIRS=	lib/security ${PKGMANDIR}/man5

do-install:
	cd ${WRKSRC} && ${SHLIBTOOL} --mode=install \
		${INSTALL_PROGRAM} pam_saml.la ${DESTDIR}${PREFIX}/lib/security
	${INSTALL_MAN} ${WRKSRC}/pam_saml.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5

.include "../../security/crudesaml/Makefile.common"
