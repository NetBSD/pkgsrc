# $NetBSD: Makefile,v 1.8 2025/11/15 01:00:22 manu Exp $
#

DISTNAME=	check_dnsrbl-0.6
PKGNAME=	nagios-plugin-dnsrbl-${DISTNAME:C/.*-//}
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/nagios-local/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	https://ftp.espci.fr/pub/nagios-local/
COMMENT=	DNSRBL monitoring plugin for Nagios
LICENSE=	modified-bsd

INSTALLATION_DIRS+=	libexec/nagios

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/check_dnsrbl \
	    ${DESTDIR}${PREFIX}/libexec/nagios/

.include "../../mk/bsd.pkg.mk"
