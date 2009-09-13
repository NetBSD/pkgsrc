# $NetBSD: Makefile,v 1.1.1.1 2009/09/13 19:57:36 manu Exp $
#

PKGNAME=	${DISTNAME:S/crudesaml-/cy2-saml-/}
COMMENT=	Crude SAML assertion validator for bridging WebSSO and SASL

PLUGINDIR=	${PREFIX}/lib/sasl2

PKG_DESTDIR_SUPPORT=    user-destdir

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PLUGINDIR}
	cd ${WRKSRC} && ${SHLIBTOOL} --mode=install \
		${INSTALL_PROGRAM} libsaml.la ${DESTDIR}${PLUGINDIR}
	${INSTALL_MAN} ${WRKSRC}/cy2_saml.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5

.include "../../security/crudesaml/Makefile.common"
