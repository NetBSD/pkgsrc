# $NetBSD: Makefile,v 1.102 2022/08/11 05:09:15 gutteridge Exp $

PKGREVISION= 12
.include "../../sysutils/cdrdao/Makefile.common"

PKGNAME=	gcdmaster-${CDRDAO_VER}
COMMENT=	Gnome UI frontend to cdrdao

DEPENDS+=	cdrdao-${CDRDAO_VER}{,nb*}:../../sysutils/cdrdao

WRKSRC=		${WRKDIR}/cdrdao-${CDRDAO_VER}

CONFIGURE_ARGS+=	--without-posix-threads
CONFIGURE_ARGS+=	--with-gcdmaster
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/applications share/pixmaps
USE_LANGUAGES+=		c++11
USE_TOOLS+=		pkg-config
INSTALL_DIRS=		gcdmaster
GCONF_SCHEMAS=		gcdmaster.schemas

.include "../../devel/libsigc++/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../devel/libgnomeuimm/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../mk/bsd.pkg.mk"
