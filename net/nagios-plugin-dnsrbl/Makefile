# $NetBSD: Makefile,v 1.1 2015/01/07 05:02:37 manu Exp $
#

PKGNAME=	nagios-plugin-dnsrbl-${DISTNAME:C/.*-//}
DISTNAME=	check_dnsrbl-0.2
#PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/nagios-local/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://ftp.espci.fr/pub/nagios-local/
COMMENT=	DNSRBL monitoring plugin for Nagios
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+= libexec/nagios

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/check_dnsrbl \
	    ${DESTDIR}${PREFIX}/libexec/nagios/

.include "../../mk/bsd.pkg.mk"
