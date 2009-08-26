# $NetBSD: Makefile,v 1.44 2009/08/26 19:58:18 sno Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../sysutils/cdrdao/Makefile.common"

PKGNAME=	gcdmaster-${CDRDAO_VER}
PKGREVISION=	6
COMMENT=	Gnome UI frontend to cdrdao

DEPENDS+=	cdrdao-${CDRDAO_VER}{,nb*}:../../sysutils/cdrdao

WRKSRC=		${WRKDIR}/cdrdao-${CDRDAO_VER}

CONFIGURE_ARGS+=	--without-posix-threads
CONFIGURE_ARGS+=	--with-xdao
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/applications share/pixmaps
USE_TOOLS+=		pkg-config
INSTALL_DIRS=		xdao

.include "../../devel/libsigc++/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../devel/libgnomeuimm/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../mk/bsd.pkg.mk"
