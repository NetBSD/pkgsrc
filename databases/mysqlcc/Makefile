# $NetBSD: Makefile,v 1.1.1.1 2003/12/21 07:58:30 martti Exp $
#

DISTNAME=		mysqlcc-0.9.4-src
PKGNAME=		${DISTNAME:S/-src//}
CATEGORIES=		databases
MASTER_SITES=		http://mirrors.sunsite.dk/mysql/Downloads/MySQLCC/ \
			ftp://sunsite.dk/mirrors/mysql/Downloads/MySQLCC/  \
			ftp://ftp.sunet.se/pub/unix/databases/relational/mysql/Downloads/MySQLCC/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.mysql.com/
COMMENT=		MySQL Control Center

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-mysql-lib=${PREFIX}/lib/mysql
CONFIGURE_ARGS+=	--with-mysql-include=${PREFIX}/include/mysql/
CONFIGURE_ARGS+=	--with-openssl-includes=${SSLBASE}/include
CONFIGURE_ARGS+=	--with-openssl-libs=${SSLBASE}/lib
CONFIGURE_ENV+=		QMAKESPEC="${QTDIR}/mkspecs/netbsd-g++"

pre-configure:
	cd ${WRKSRC} && ${ACLOCAL} && ${AUTOCONF}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mysqlcc ${PREFIX}/bin/
	
.include "../../mk/autoconf.mk"
.include "../../mk/automake.mk"
.include "../../databases/mysql4-client/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../x11/qt3-tools/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
