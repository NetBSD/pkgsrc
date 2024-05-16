# $NetBSD: Makefile,v 1.25 2024/05/16 06:15:13 wiz Exp $

DISTNAME=	gerbera-1.12.1
PKGREVISION=	10
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=gerbera/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gerbera/gerbera
COMMENT=	UPnP Media Server
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	filesystem

RCD_SCRIPTS=	gerbera

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	VARBASE

GERBERA_USER?=	gerbera
GERBERA_GROUP?=	gerbera

PKG_GROUPS=	${GERBERA_GROUP}
PKG_USERS=	${GERBERA_USER}:${GERBERA_GROUP}

PKG_GECOS.${GERBERA_USER}=	Gerbera Server
PKG_HOME.${GERBERA_USER}=	${VARBASE}/gerbera

PKG_SYSCONFSUBDIR=	gerbera
EGDIR=			${PREFIX}/share/examples/gerbera
CONF_FILES_PERMS+=	${EGDIR}/config.xml ${PKG_SYSCONFDIR}/config.xml \
			${GERBERA_USER} ${GERBERA_GROUP} 0640

FILES_SUBST+=		PKG_HOME=${PKG_HOME.${GERBERA_USER}}
FILES_SUBST+=		GERBERA_GROUP=${GERBERA_GROUP}
FILES_SUBST+=		GERBERA_USER=${GERBERA_USER}
FILES_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

GERBERA_HOME=		${PKG_HOME.${GERBERA_USER}}

SUBST_CLASSES+=		config
SUBST_FILES.config=	config.xml gerbera.desktop
SUBST_VARS.config=	GERBERA_HOME PREFIX OPSYS
SUBST_STAGE.config=	pre-configure

INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/examples/gerbera
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

CHECK_SHLIBS_SUPPORTED=	no

post-extract:
	${CP} ${FILESDIR}/config.xml.in ${WRKSRC}/config.xml
	${CP} ${FILESDIR}/gerbera.desktop.in ${WRKSRC}/gerbera.desktop

post-install:
	${INSTALL_DATA} ${WRKSRC}/config.xml ${DESTDIR}${EGDIR}/config.xml
	${INSTALL_DATA} ${WRKSRC}/gerbera.desktop \
		${DESTDIR}${PREFIX}/share/applications/gerbera.desktop
.if ${PKGMANDIR} != "share/man"
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/gerbera.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/gerbera.1
.endif

.include "options.mk"

.include "../../audio/taglib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.if !empty(PKGSRC_COMPILER:M*gcc*)
.  include "../../devel/libatomic/buildlink3.mk"
.endif
.include "../../devel/libebml/buildlink3.mk"
.include "../../devel/libinotify/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/spdlog/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../net/libupnp/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../textproc/pugixml/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
