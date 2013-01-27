# $NetBSD: Makefile,v 1.2 2013/01/27 09:05:10 asau Exp $
#

PKGNAME=	nagios-plugin-raidctl-${DISTNAME:C/.*-//}
DISTNAME=	check_raidctl-0.1
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/nagios-local/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://ftp.espci.fr/pub/nagios-local/
COMMENT=	RAIDframe monitoring plugin for Nagios
LICENSE=	modified-bsd

INSTALLATION_DIRS+= libexec/nagios

SPECIAL_PERMS+= ${PREFIX}/libexec/nagios/check_raidctl \
		${REAL_ROOT_USER} ${NAGIOS_GROUP} 4551
BUILD_DEFS+=	${NAGIOS_GROUP}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/check_raidctl \
	    ${DESTDIR}${PREFIX}/libexec/nagios/

.include "../../mk/bsd.pkg.mk"
