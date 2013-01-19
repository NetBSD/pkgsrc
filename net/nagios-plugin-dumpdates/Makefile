# $NetBSD: Makefile,v 1.1 2013/01/19 10:24:41 manu Exp $
#

PKGNAME=	nagios-plugin-dumpdates-${DISTNAME:C/.*-//}
DISTNAME=	check_dumpdates-0.1
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/nagios-local/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://ftp.espci.fr/pub/nagios-local/
COMMENT=	/etc/dumpdates monitoring plugin for Nagios
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+= libexec/nagios

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/check_dumpdates \
	    ${DESTDIR}${PREFIX}/libexec/nagios/

.include "../../mk/bsd.pkg.mk"
