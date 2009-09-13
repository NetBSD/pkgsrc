# $NetBSD: Makefile,v 1.1.1.1 2009/09/13 19:57:51 manu Exp $
#

PKGNAME=	${DISTNAME:S/crudesaml-/pam-saml-/}
COMMENT=	Crude SAML assertion validator for bridging WebSSO and PAM

PKG_DESTDIR_SUPPORT=    user-destdir

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/security
	cd ${WRKSRC} && ${SHLIBTOOL} --mode=install \
		${INSTALL_PROGRAM} pam_saml.la ${DESTDIR}${PREFIX}/lib/security
	${INSTALL_MAN} ${WRKSRC}/pam_saml.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5

.include "../../security/crudesaml/Makefile.common"
