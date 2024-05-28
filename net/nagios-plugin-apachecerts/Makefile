# $NetBSD: Makefile,v 1.2 2024/05/28 13:14:28 manu Exp $
#

DISTNAME=	check_apachecerts-0.7
PKGNAME=	nagios-plugin-apachecerts-${DISTNAME:C/.*-//}
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/nagios-local/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ftp.espci.fr/pub/nagios-local/
COMMENT=	Apache certificate expiration monitoring plugin for Nagios
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+=	libexec/nagios


BUILD_DEFS+=		NAGIOS_GROUP
PKG_GROUPS_VARS+=	NAGIOS_GROUP
PKG_GROUPS=		${NAGIOS_GROUP}

SPECIAL_PERMS+=	${PREFIX}/libexec/nagios/check_apachecerts \
		${REAL_ROOT_USER} ${NAGIOS_GROUP} 4554

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/check_apachecerts \
	    ${DESTDIR}${PREFIX}/libexec/nagios/

.include "../../mk/bsd.pkg.mk"
