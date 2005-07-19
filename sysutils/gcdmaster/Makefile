# $NetBSD: Makefile,v 1.26 2005/07/19 16:36:51 drochner Exp $
#

.include "../../sysutils/cdrdao/Makefile.common"

PKGREVISION=		3

PKGNAME=		gcdmaster-${CDRDAO_VER}
COMMENT=		Gnome UI frontend to cdrdao

DEPENDS+=		cdrdao-${CDRDAO_VER}{,nb*}:../../sysutils/cdrdao

WRKSRC=			${WRKDIR}/cdrdao-${CDRDAO_VER}

USE_X11BASE=		YES
USE_DIRS+=		gnome1-1.5
CONFIGURE_ARGS+=	--without-posix-threads
CONFIGURE_ARGS+=	--with-xdao
INSTALLATION_DIRS=	bin man/man1 share/applications share/pixmaps

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

.include "../../devel/libgnomeuimm26/buildlink3.mk"
.include "../../devel/libgnomemm26/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/gtkmm24/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
