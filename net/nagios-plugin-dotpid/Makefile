# $NetBSD: Makefile,v 1.3 2015/03/22 19:44:28 rodent Exp $
#

PKGNAME=	nagios-plugin-dotpid-${DISTNAME:C/.*-//}
DISTNAME=	check_dotpid-0.3
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/nagios-local/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://ftp.espci.fr/pub/nagios-local/
COMMENT=	/var/run/*.pid monitoring plugin for Nagios
LICENSE=	modified-bsd

INSTALLATION_DIRS+= libexec/nagios

SPECIAL_PERMS+= ${PREFIX}/libexec/nagios/check_dotpid \
		${REAL_ROOT_USER} ${NAGIOS_GROUP} 4551
BUILD_DEFS+=	${NAGIOS_GROUP}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/check_dotpid \
	    ${DESTDIR}${PREFIX}/libexec/nagios/

.include "../../mk/bsd.pkg.mk"
