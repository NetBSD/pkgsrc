# $NetBSD: Makefile,v 1.2 2023/07/12 20:14:48 nia Exp $
#

DISTNAME=	check_mqueue-0.1
PKGNAME=	nagios-plugin-mqueue-${DISTNAME:C/.*-//}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/nagios-local/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ftp.espci.fr/pub/nagios-local/
COMMENT=	Sendmail queue monitoring plugin for Nagios
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+=	libexec/nagios


BUILD_DEFS+=		NAGIOS_GROUP
PKG_GROUPS_VARS+=	NAGIOS_GROUP
PKG_GROUPS=		${NAGIOS_GROUP}

SPECIAL_PERMS+=	${PREFIX}/libexec/nagios/check_mqueue \
		${REAL_ROOT_USER} ${NAGIOS_GROUP} 4554

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/check_mqueue \
	    ${DESTDIR}${PREFIX}/libexec/nagios/

.include "../../mk/bsd.pkg.mk"
