# $NetBSD: Makefile,v 1.21 2008/01/18 05:06:28 tnn Exp $
#

DISTNAME=		mysqlcc-0.9.4-src
PKGNAME=		${DISTNAME:S/-src//}
PKGREVISION=		9
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_MYSQL:=MySQLCC/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.mysql.com/
COMMENT=		MySQL Control Center

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		automake
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	\
	--with-mysql-lib=${BUILDLINK_PREFIX.mysql-client}/lib/mysql
CONFIGURE_ARGS+=	\
	--with-mysql-include=${BUILDLINK_PREFIX.mysql-client}/include/mysql
CONFIGURE_ARGS+=	--with-openssl-includes=${SSLBASE}/include
CONFIGURE_ARGS+=	--with-openssl-lib=${SSLBASE}/lib
CONFIGURE_ENV+=		QMAKESPEC="${QTDIR}/mkspecs/netbsd-g++"

MYSQL_VERSIONS_ACCEPTED=	41

INSTALLATION_DIRS=	bin

pre-configure:
	cd ${WRKSRC} && aclocal && autoconf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mysqlcc ${PREFIX}/bin/

.include "../../security/openssl/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
