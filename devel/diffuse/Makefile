# $NetBSD: Makefile,v 1.1.1.1 2008/12/09 14:19:21 wiz Exp $
#

DISTNAME=	diffuse-0.2.15
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=diffuse/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://diffuse.sourceforge.net/
COMMENT=	Graphical tool for merging and comparing text files

USE_LANGUAGES=	# none
USE_DIRS=	xdg-1.4 gnome2-1.6

INSTALLATION_DIRS=	bin share/diffuse/syntax share/examples/diffuse
INSTALLATION_DIRS+=	share/gnome/help/diffuse

CONF_FILES+=	${PREFIX}/share/examples/diffuse/diffuserc \
		${PKG_SYSCONFDIR}/diffuserc

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
		${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/src/usr/share/gnome/help/diffuse/C/diffuse.xml \
		${DESTDIR}${PREFIX}/share/gnome/help/diffuse/C
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
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
