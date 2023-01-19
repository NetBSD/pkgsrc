# $NetBSD: Makefile,v 1.1 2023/01/19 15:15:02 manu Exp $
#

PKGNAME=	nagios-plugin-x509-${DISTNAME:C/.*-//}
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
