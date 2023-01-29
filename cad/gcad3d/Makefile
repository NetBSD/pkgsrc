# $NetBSD: Makefile,v 1.5 2023/01/29 21:15:34 ryoon Exp $
#

#
# gCAD3D is open source but not open development. Each release is added
# to github as a single commit, with the message as the ChangeLog. So,
# the tag is needed to fetch the right version.
#

DISTNAME=	gcad3d-2.46.24
PKGREVISION=	3
CATEGORIES=	cad editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=gcad3d/}
GITHUB_PROJECT=	gcad3d
GITHUB_TAG=	ff33b206f158092dbac7f2b1236c3d38fee5d656

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gcad3d.org/
COMMENT=	3D CADCAM software
LICENSE=	gnu-gpl-v3

USE_TOOLS=	gmake pkg-config
USE_LANGUAGES=	c99
TOOLS_NOOP+=	ctags	# exctags is used but not needed

WRKSRC=		${WRKDIR}/${PKGBASE}-${GITHUB_TAG}

REPLACE_SH+=	src/APP/del_obj.sh

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing hardcoded paths
SUBST_FILES.paths=	src/gcad3d
SUBST_VARS.paths=	PREFIX

#
# The gCAD3D build system is a custom shell script plus a bunch of makefiles
# with no way to add flags. We leverage cwrappers to wedge the flags we need
# for pkgsrc in there. pkglint suggests to use :Q but we don't want that.
#
CWRAPPERS_PREPEND.cc=	${CFLAGS} ${CPPFLAGS} ${LDFLAGS}

BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
DL_AUTO_VARS=		yes

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--unresolved-symbols=ignore-all
BUILDLINK_TRANSFORM.SunOS+=	rm:-export-dynamic

ALL_ENV+=		DIR_DEV=${WRKSRC}/
ALL_ENV+=		DIR_BIN=${WRKSRC}/

INSTALLATION_DIRS=	bin lib/gcad3d/plugins/cut1 share/applications share/pixmaps
INSTALLATION_DIRS+=	share/gcad3d/icons share/doc/gcad3d/html share/doc/gcad3d/msg

do-configure:
	cd ${WRKSRC}/src/APP && env ${CONFIGURE_ENV} ./do debug_OFF

do-build:
	cd ${WRKSRC}/src/APP && env ${MAKE_ENV} ./do complete

# see rpm/gcad3d.spec
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/gcad3d ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/gcad3d/gCAD3D ${DESTDIR}${PREFIX}/lib/gcad3d
	${INSTALL_PROGRAM} ${WRKSRC}/gcad3d/GUI_dlg1_gtk2 ${DESTDIR}${PREFIX}/lib/gcad3d
	${INSTALL_PROGRAM} ${WRKSRC}/gcad3d/GUI_file_gtk2 ${DESTDIR}${PREFIX}/lib/gcad3d
	${INSTALL_LIB} ${WRKSRC}/gcad3d/*.so ${DESTDIR}${PREFIX}/lib/gcad3d
	${INSTALL_LIB} ${WRKSRC}/gcad3d/plugins/*.so ${DESTDIR}${PREFIX}/lib/gcad3d/plugins
	${INSTALL_LIB} ${WRKSRC}/gcad3d/plugins/cut1/* ${DESTDIR}${PREFIX}/lib/gcad3d/plugins/cut1
	${INSTALL_DATA} ${WRKSRC}/src/gcad3d.desktop ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/icons/gCAD3D.xpm ${DESTDIR}${PREFIX}/share/pixmaps/gcad3d.xpm
	${INSTALL_DATA} ${WRKSRC}/packages/examples.gz ${DESTDIR}${PREFIX}/share/gcad3d
	${INSTALL_DATA} ${WRKSRC}/icons/*.png ${DESTDIR}${PREFIX}/share/gcad3d/icons
	${INSTALL_DATA} ${WRKSRC}/icons/*.xpm ${DESTDIR}${PREFIX}/share/gcad3d/icons
	${INSTALL_DATA} ${WRKSRC}/icons/*.bmp ${DESTDIR}${PREFIX}/share/gcad3d/icons
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.htm ${DESTDIR}${PREFIX}/share/doc/gcad3d/html
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.png ${DESTDIR}${PREFIX}/share/doc/gcad3d/html
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.js ${DESTDIR}${PREFIX}/share/doc/gcad3d/html
	${INSTALL_DATA} ${WRKSRC}/doc/msg/*.txt ${DESTDIR}${PREFIX}/share/doc/gcad3d/msg
	${INSTALL_DATA} ${WRKSRC}/doc/gCAD3D_log.txt ${DESTDIR}${PREFIX}/share/doc/gcad3d/NEWS
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/gcad3d
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/share/doc/gcad3d

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtkglarea2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
