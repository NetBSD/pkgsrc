# $NetBSD: Makefile,v 1.45 2015/04/25 14:20:31 tnn Exp $
#

DISTNAME=		mysqlcc-1.0.2-src
PKGNAME=		${DISTNAME:S/-src//}
PKGREVISION=		2
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mysqlcc/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mysqlcc.sourceforge.net/
COMMENT=		MySQL Control Center
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	\
	--with-mysql-lib=${BUILDLINK_PREFIX.mysql-client}/${BUILDLINK_LIBDIRS.mysql-client}
CONFIGURE_ARGS+=	\
	--with-mysql-include=${BUILDLINK_PREFIX.mysql-client}/${BUILDLINK_INCDIRS.mysql-client}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	src/CApplication.cpp
SUBST_SED.paths=	-e "s|@PREFIX@|${PREFIX}|"
SUBST_MESSAGE.paths=	Fixing paths.

INSTALLATION_DIRS=	bin share/mysqlcc/translations
SUPPORT_FILES=		error.wav information.wav syntax.txt warning.wav

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mysqlcc ${DESTDIR}${PREFIX}/bin
.for f in ${SUPPORT_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/mysqlcc
.endfor
	${INSTALL_DATA} ${WRKSRC}/translations/*.qm \
		${DESTDIR}${PREFIX}/share/mysqlcc/translations
	${INSTALL_DATA} ${WRKSRC}/translations/*.ts \
		${DESTDIR}${PREFIX}/share/mysqlcc/translations

.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
