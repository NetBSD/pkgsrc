# $NetBSD: Makefile,v 1.3 2023/10/24 22:10:26 wiz Exp $
#

PKGNAME=	nagios-plugin-x509-${DISTNAME:C/.*-//}
PKGREVISION=	2
DISTNAME=	check_x509-0.1
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/nagios-local/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	https://ftp.espci.fr/pub/nagios-local/
COMMENT=	x509 certificate validation plugin for Nagios
LICENSE=	modified-bsd

INSTALLATION_DIRS+=	libexec/nagios

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/check_x509 \
	    ${DESTDIR}${PREFIX}/libexec/nagios/

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
