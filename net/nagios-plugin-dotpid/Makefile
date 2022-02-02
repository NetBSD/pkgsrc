# $NetBSD: Makefile,v 1.10 2022/02/02 15:06:43 manu Exp $
#

PKGNAME=	nagios-plugin-dotpid-${DISTNAME:C/.*-//}
#PKGREVISION=	1
DISTNAME=	check_dotpid-0.7
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/nagios-local/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	https://ftp.espci.fr/pub/nagios-local/
COMMENT=	/var/run/*.pid monitoring plugin for Nagios
LICENSE=	modified-bsd

INSTALLATION_DIRS+=	libexec/nagios

BUILD_DEFS+=		NAGIOS_GROUP
PKG_GROUPS_VARS=	NAGIOS_GROUP
PKG_GROUPS=		${NAGIOS_GROUP}

SPECIAL_PERMS+=	${PREFIX}/libexec/nagios/check_dotpid \
		${REAL_ROOT_USER} ${NAGIOS_GROUP} 4551

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/check_dotpid \
	    ${DESTDIR}${PREFIX}/libexec/nagios/

.include "../../mk/bsd.pkg.mk"
