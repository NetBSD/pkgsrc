# $NetBSD: Makefile,v 1.7 2023/01/09 00:42:46 sekiya Exp $
#

DISTNAME=	check_mysql_slave-0.2
PKGNAME=	nagios-plugin-mysqlslave-${DISTNAME:C/.*-//}
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/nagios-local/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	https://ftp.espci.fr/pub/nagios-local/
COMMENT=	MySQL and MariaDB slave monitoring plugin for Nagios
LICENSE=	modified-bsd

MAKE_ENV+=	PREFIX=${PREFIX}

INSTALLATION_DIRS+=	libexec/nagios

BUILD_DEFS+=		NAGIOS_GROUP
PKG_GROUPS_VARS+=	NAGIOS_GROUP
PKG_GROUPS=		${NAGIOS_GROUP}

SPECIAL_PERMS+=	${PREFIX}/libexec/nagios/check_mysql_slave \
		${REAL_ROOT_USER} ${NAGIOS_GROUP} 4554

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/check_mysql_slave \
	    ${DESTDIR}${PREFIX}/libexec/nagios/

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
