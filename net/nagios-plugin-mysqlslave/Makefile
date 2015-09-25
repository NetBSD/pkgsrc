# $NetBSD: Makefile,v 1.1 2015/09/25 13:18:45 manu Exp $
#

PKGNAME=	nagios-plugin-mysqlslave-${DISTNAME:C/.*-//}
DISTNAME=	check_mysql_slave-0.1
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/nagios-local/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://ftp.espci.fr/pub/nagios-local/
COMMENT=	MySQL and MariaDB slave monitoring plugin for Nagios
LICENSE=	modified-bsd

MAKE_ENV+=	PREFIX=${PREFIX}

INSTALLATION_DIRS+= libexec/nagios

SPECIAL_PERMS+= ${PREFIX}/libexec/nagios/check_mysql_slave \
		${REAL_ROOT_USER} ${NAGIOS_GROUP} 4554
BUILD_DEFS+=	${NAGIOS_GROUP}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/check_mysql_slave \
	    ${DESTDIR}${PREFIX}/libexec/nagios/

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
