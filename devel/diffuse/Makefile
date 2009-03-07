# $NetBSD: Makefile,v 1.6 2009/03/07 03:02:09 wiz Exp $
#

DISTNAME=	diffuse-0.2.15
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=diffuse/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://diffuse.sourceforge.net/
COMMENT=	Graphical tool for merging and comparing text files

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
USE_DIRS=	xdg-1.4 gnome2-1.6

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/applications
INSTALLATION_DIRS+=	share/diffuse/syntax share/examples/diffuse
INSTALLATION_DIRS+=	share/gnome/help/diffuse share/pixmaps

CONF_FILES+=	${PREFIX}/share/examples/diffuse/diffuserc \
		${PKG_SYSCONFDIR}/diffuserc

PYTHON_VERSIONS_ACCEPTED=	25 24
REPLACE_PYTHON=		src/usr/bin/diffuse

SUBST_CLASSES+=		paths
SUBST_FILES.paths+=	src/etc/diffuserc
SUBST_FILES.paths+=	src/usr/bin/diffuse
SUBST_FILES.paths+=	src/usr/share/omf/diffuse/diffuse-C.omf
SUBST_FILES.paths+=	src/usr/share/man/man1/diffuse.1
SUBST_SED.paths+=	-e "s,/usr,${PREFIX},"
SUBST_SED.paths+=	-e "s,/etc,${PKG_SYSCONFDIR},"
SUBST_STAGE.paths=	post-patch
SUBST_MESSAGE.paths=	Fixing hardcoded paths.

do-build:
	# nothing

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/usr/bin/diffuse ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/usr/share/pixmaps/diffuse.png \
		${DESTDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/gnome/help/diffuse/C
	${INSTALL_DATA} ${WRKSRC}/src/usr/share/gnome/help/diffuse/C/diffuse.xml \
		${DESTDIR}${PREFIX}/share/gnome/help/diffuse/C
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/omf/diffuse
	${INSTALL_DATA} ${WRKSRC}/src/usr/share/omf/diffuse/diffuse-C.omf \
		${DESTDIR}${PREFIX}/share/omf/diffuse
	${INSTALL_DATA} ${WRKSRC}/src/usr/share/applications/diffuse.desktop \
		${DESTDIR}${PREFIX}/share/applications
	${INSTALL_MAN} ${WRKSRC}/src/usr/share/man/man1/diffuse.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/src/usr/share/diffuse/syntax/* \
		${DESTDIR}${PREFIX}/share/diffuse/syntax
	${INSTALL_DATA} ${WRKSRC}/src/etc/diffuserc \
		${DESTDIR}${PREFIX}/share/examples/diffuse

.include "../../lang/python/application.mk"
.include "../../mk/omf-scrollkeeper.mk"
BUILDLINK_API_DEPENDS.pygtk2+=	${PYPKGPREFIX}-gtk2>=2.10
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
