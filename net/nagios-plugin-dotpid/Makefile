# $NetBSD: Makefile,v 1.6 2017/08/07 09:19:19 jlam Exp $
#

PKGNAME=	nagios-plugin-dotpid-${DISTNAME:C/.*-//}
PKGREVISION=	1
DISTNAME=	check_dotpid-0.5
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/nagios-local/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://ftp.espci.fr/pub/nagios-local/
COMMENT=	/var/run/*.pid monitoring plugin for Nagios
LICENSE=	modified-bsd

INSTALLATION_DIRS+= libexec/nagios

BUILD_DEFS+=		NAGIOS_GROUP
PKG_GROUPS_VARS=	NAGIOS_GROUP
PKG_GROUPS=		${NAGIOS_GROUP}

SPECIAL_PERMS+= ${PREFIX}/libexec/nagios/check_dotpid \
		${REAL_ROOT_USER} ${NAGIOS_GROUP} 4551

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/check_dotpid \
	    ${DESTDIR}${PREFIX}/libexec/nagios/

.include "../../mk/bsd.pkg.mk"
