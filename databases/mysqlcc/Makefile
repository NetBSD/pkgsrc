# $NetBSD: Makefile,v 1.25 2009/08/26 19:57:19 sno Exp $
#

DISTNAME=		mysqlcc-0.9.4-src
PKGNAME=		${DISTNAME:S/-src//}
PKGREVISION=		10
CATEGORIES=		databases
MASTER_SITES=		# ${MASTER_SITE_SOURCEFORGE:=mysqlcc/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mysqlcc.sourceforge.net/
COMMENT=		MySQL Control Center

PKG_DESTDIR_SUPPORT=	user-destdir

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
	${INSTALL_PROGRAM} ${WRKSRC}/mysqlcc ${DESTDIR}${PREFIX}/bin

.include "../../security/openssl/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
