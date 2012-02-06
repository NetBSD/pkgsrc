# $NetBSD: Makefile,v 1.4 2012/02/06 12:41:27 wiz Exp $
#

PKGNAME=	${DISTNAME:S/crudesaml-/pam-saml-/}
PKGREVISION=	2
COMMENT=	Crude SAML assertion validator for bridging WebSSO and PAM

PKG_DESTDIR_SUPPORT=    user-destdir
INSTALLATION_DIRS=	lib/security ${PKGMANDIR}/man5

do-install:
	cd ${WRKSRC} && ${SHLIBTOOL} --mode=install \
		${INSTALL_PROGRAM} pam_saml.la ${DESTDIR}${PREFIX}/lib/security
	${INSTALL_MAN} ${WRKSRC}/pam_saml.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5

.include "../../security/crudesaml/Makefile.common"
