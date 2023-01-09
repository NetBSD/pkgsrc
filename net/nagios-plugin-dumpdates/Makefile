# $NetBSD: Makefile,v 1.7 2023/01/09 00:42:46 sekiya Exp $
#

DISTNAME=	check_dumpdates-0.3
PKGNAME=	nagios-plugin-dumpdates-${DISTNAME:C/.*-//}
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/nagios-local/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	https://ftp.espci.fr/pub/nagios-local/
COMMENT=	/etc/dumpdates monitoring plugin for Nagios
LICENSE=	modified-bsd

INSTALLATION_DIRS+=	libexec/nagios

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/check_dumpdates \
	    ${DESTDIR}${PREFIX}/libexec/nagios/

.include "../../mk/bsd.pkg.mk"
