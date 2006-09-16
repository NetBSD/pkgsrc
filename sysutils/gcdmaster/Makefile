# $NetBSD: Makefile,v 1.34 2006/09/16 12:20:40 jmmv Exp $

.include "../../sysutils/cdrdao/Makefile.common"

PKGNAME=	gcdmaster-${CDRDAO_VER}
PKGREVISION=	1
COMMENT=	Gnome UI frontend to cdrdao

DEPENDS+=	cdrdao-${CDRDAO_VER}{,nb*}:../../sysutils/cdrdao

WRKSRC=		${WRKDIR}/cdrdao-${CDRDAO_VER}

USE_X11BASE=		yes
USE_DIRS+=		gnome1-1.5
CONFIGURE_ARGS+=	--without-posix-threads
CONFIGURE_ARGS+=	--with-xdao
INSTALLATION_DIRS=	bin man/man1 share/applications share/pixmaps
USE_TOOLS+=		pkg-config

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdao/gcdmaster ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xdao/gcdmaster.man \
		${PREFIX}/man/man1/gcdmaster.1
	${INSTALL_DATA} ${WRKSRC}/xdao/gcdmaster.desktop \
		${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/xdao/gcdmaster.png \
		${PREFIX}/share/pixmaps
	${INSTALL_DATA_DIR} ${PREFIX}/share/gcdmaster/glade
	${INSTALL_DATA} ${WRKSRC}/xdao/glade/ProjectChooser.glade \
		${PREFIX}/share/gcdmaster/glade

.include "../../devel/libsigc++2/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../devel/libgnomeuimm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
