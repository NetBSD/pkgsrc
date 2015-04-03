# $NetBSD: Makefile,v 1.3 2015/04/03 18:04:56 rodent Exp $
#

PKGNAME=	nagios-plugin-dumpdates-${DISTNAME:C/.*-//}
DISTNAME=	check_dumpdates-0.2
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/nagios-local/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://ftp.espci.fr/pub/nagios-local/
COMMENT=	/etc/dumpdates monitoring plugin for Nagios
LICENSE=	modified-bsd

INSTALLATION_DIRS+= libexec/nagios

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/check_dumpdates \
	    ${DESTDIR}${PREFIX}/libexec/nagios/

.include "../../mk/bsd.pkg.mk"
