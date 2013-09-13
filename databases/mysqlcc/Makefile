# $NetBSD: Makefile,v 1.42 2013/09/13 12:29:19 obache Exp $
#

DISTNAME=		mysqlcc-0.9.8-src
PKGNAME=		${DISTNAME:S/-src//}
PKGREVISION=		13
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mysqlcc/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mysqlcc.sourceforge.net/
COMMENT=		MySQL Control Center

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		autoconf automake
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	\
	--with-mysql-lib=${BUILDLINK_PREFIX.mysql-client}/lib/mysql
CONFIGURE_ARGS+=	\
	--with-mysql-include=${BUILDLINK_PREFIX.mysql-client}/include/mysql
CONFIGURE_ARGS+=	--with-openssl-includes=${SSLBASE}/include
CONFIGURE_ARGS+=	--with-openssl-lib=${SSLBASE}/lib
CONFIGURE_ENV+=		QMAKESPEC="${QTDIR}/mkspecs/netbsd-g++"

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	src/CApplication.cpp
SUBST_SED.paths=	-e "s|@PREFIX@|${PREFIX}|"
SUBST_MESSAGE.paths=	Fixing paths.

BROKEN=		"MySQL 5.1 and later API is not supported"

INSTALLATION_DIRS=	bin share/mysqlcc/translations
SUPPORT_FILES=		error.wav information.wav syntax.txt warning.wav

pre-configure:
	cd ${WRKSRC} && aclocal && autoconf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mysqlcc ${DESTDIR}${PREFIX}/bin
.for f in ${SUPPORT_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/mysqlcc
.endfor
	${INSTALL_DATA} ${WRKSRC}/translations/*.qm \
		${DESTDIR}${PREFIX}/share/mysqlcc/translations
	${INSTALL_DATA} ${WRKSRC}/translations/*.ts \
		${DESTDIR}${PREFIX}/share/mysqlcc/translations

.include "../../security/openssl/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
