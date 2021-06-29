# $NetBSD: Makefile,v 1.7 2021/06/29 00:08:50 tnn Exp $
#

PKGNAME=	nagios-plugin-raidctl-${DISTNAME:C/.*-//}
PKGREVISION=	1
DISTNAME=	check_raidctl-0.1
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/nagios-local/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	https://ftp.espci.fr/pub/nagios-local/
COMMENT=	RAIDframe monitoring plugin for Nagios
LICENSE=	modified-bsd

ONLY_FOR_PLATFORM=	NetBSD-*-* OpenBSD-*-*

INSTALLATION_DIRS+=	libexec/nagios

BUILD_DEFS+=		NAGIOS_GROUP
PKG_GROUPS_VARS+=	NAGIOS_GROUP
PKG_GROUPS=		${NAGIOS_GROUP}

SPECIAL_PERMS+=	${PREFIX}/libexec/nagios/check_raidctl \
		${REAL_ROOT_USER} ${NAGIOS_GROUP} 4554

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/check_raidctl \
	    ${DESTDIR}${PREFIX}/libexec/nagios/

.include "../../mk/bsd.pkg.mk"
