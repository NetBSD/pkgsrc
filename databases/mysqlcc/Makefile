# $NetBSD: Makefile,v 1.7 2005/03/16 13:16:15 rillig Exp $
#

DISTNAME=		mysqlcc-0.9.4-src
PKGNAME=		${DISTNAME:S/-src//}
PKGREVISION=		4
CATEGORIES=		databases
MASTER_SITES=		http://mirrors.sunsite.dk/mysql/Downloads/MySQLCC/ \
			ftp://sunsite.dk/mirrors/mysql/Downloads/MySQLCC/  \
			ftp://ftp.sunet.se/pub/unix/databases/relational/mysql/Downloads/MySQLCC/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.mysql.com/
COMMENT=		MySQL Control Center

USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	\
	--with-mysql-lib=${BUILDLINK_PREFIX.mysql-client}/lib/mysql
CONFIGURE_ARGS+=	\
	--with-mysql-include=${BUILDLINK_PREFIX.mysql-client}/include/mysql
CONFIGURE_ARGS+=	--with-openssl-includes=${SSLBASE}/include
CONFIGURE_ARGS+=	--with-openssl-lib=${SSLBASE}/lib
CONFIGURE_ENV+=		QMAKESPEC="${QTDIR}/mkspecs/netbsd-g++"

MYSQL_VERSIONS_ACCEPTED=	40 41

pre-configure:
	cd ${WRKSRC} && ${ACLOCAL} && ${AUTOCONF}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mysqlcc ${PREFIX}/bin/

.include "../../security/openssl/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
