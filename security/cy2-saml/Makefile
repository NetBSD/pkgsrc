# $NetBSD: Makefile,v 1.23 2023/04/19 08:11:20 adam Exp $

PKGNAME=	${DISTNAME:S/crudesaml-/cy2-saml-/}
PKGREVISION=	10
COMMENT=	Crude SAML assertion validator for bridging WebSSO and SASL

PLUGINDIR=	${PREFIX}/lib/sasl2

INSTALLATION_DIRS=	${PKGMANDIR}/man5 ${PLUGINDIR}

do-install:
	${SHLIBTOOL} --mode=install \
		${INSTALL_PROGRAM} ${WRKSRC}/libsaml.la ${DESTDIR}${PLUGINDIR}
	${INSTALL_MAN} ${WRKSRC}/cy2_saml.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5

.include "../../security/crudesaml/Makefile.common"
