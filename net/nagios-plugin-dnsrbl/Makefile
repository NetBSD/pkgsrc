# $NetBSD: Makefile,v 1.4 2017/09/08 02:26:20 manu Exp $
#

PKGNAME=	nagios-plugin-dnsrbl-${DISTNAME:C/.*-//}
DISTNAME=	check_dnsrbl-0.4
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/nagios-local/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://ftp.espci.fr/pub/nagios-local/
COMMENT=	DNSRBL monitoring plugin for Nagios
LICENSE=	modified-bsd

INSTALLATION_DIRS+= libexec/nagios

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/check_dnsrbl \
	    ${DESTDIR}${PREFIX}/libexec/nagios/

.include "../../mk/bsd.pkg.mk"
