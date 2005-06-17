# $NetBSD: Makefile,v 1.25 2005/06/17 03:50:34 jlam Exp $
#

.include "../../sysutils/cdrdao/Makefile.common"

PKGNAME=		gcdmaster-${CDRDAO_VER}
COMMENT=		Gnome UI frontend to cdrdao

DEPENDS+=		cdrdao-${PKGVERSION}:../../sysutils/cdrdao

PKGDIR=         	${.CURDIR}/../../sysutils/cdrdao
FILESDIR=       	${PKGDIR}/files
PATCHDIR=       	${PKGDIR}/patches
DISTINFO_FILE=  	${PKGDIR}/distinfo
PLIST_SRC=		${PKGDIR}/PLIST.gcdmaster
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

.include "../../devel/libgnomeuimm26/buildlink3.mk"
.include "../../devel/libgnomemm26/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/gtkmm24/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
