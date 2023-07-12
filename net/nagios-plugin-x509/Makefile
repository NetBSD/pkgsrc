# $NetBSD: Makefile,v 1.2 2023/07/12 20:17:12 nia Exp $
#

PKGNAME=	nagios-plugin-x509-${DISTNAME:C/.*-//}
PKGREVISION=	1
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
