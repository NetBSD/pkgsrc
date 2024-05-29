# $NetBSD: Makefile,v 1.42 2024/05/29 16:34:03 adam Exp $

DISTNAME=	syncthing-gtk-0.9.4.5
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=syncthing-gtk/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/syncthing-gtk/syncthing-gtk
COMMENT=	GTK3 & Python based GUI for Syncthing
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	syncthing>=0.13.0:../../net/syncthing
DEPENDS+=	glib-networking-[0-9]*:../../net/glib-networking
DEPENDS+=	psmisc-[0-9]*:../../sysutils/psmisc
DEPENDS+=	${PYPKGPREFIX}-bcrypt-[0-9]*:../../security/py-bcrypt
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_PYTHON+=		*.py scripts/*.py syncthing_gtk/*.py

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

SUBST_CLASSES+=		path_s
SUBST_STAGE.path_s=	pre-build
SUBST_MESSAGE.path_s=	Fixing hard-coded paths to /usr/share
SUBST_FILES.path_s=	scripts/syncthing-gtk
SUBST_FILES.path_s+=	syncthing_gtk/app.py
SUBST_FILES.path_s+=	syncthing_gtk/uisettingsdialog.py
SUBST_FILES.path_s+=	syncthing_gtk/wizard.py
SUBST_SED.path_s=	-e 's|/usr/share/icons|${PREFIX}/share/icons|'
SUBST_SED.path_s+=	-e 's|/usr/share/syncthing-gtk|${PREFIX}/share/syncthing-gtk|'

SUBST_CLASSES+=		path_b
SUBST_STAGE.path_b=	pre-build
SUBST_MESSAGE.path_b=	Fixing hard-coded paths to /usr/bin
SUBST_FILES.path_b=	syncthing_gtk/app.py
SUBST_FILES.path_b+=	syncthing_gtk/configuration.py
SUBST_FILES.path_b+=	syncthing_gtk/uisettingsdialog.py
SUBST_SED.path_b=	-e 's|/usr/bin/%s|${PREFIX}/bin/%s|'
SUBST_SED.path_b+=	-e 's|/usr/bin/syncthing|${PREFIX}/bin/syncthing|'
SUBST_SED.path_b+=	-e 's|"/usr/bin"|"${PREFIX}/bin"|'

post-install:
	cd ${DESTDIR}${PREFIX} && ${MV} share/man/man1/* ${PKGMANDIR}/man1

BUILDLINK_API_DEPENDS.libnotify+=	libnotify>=0.7.8
.include "../../sysutils/libnotify/buildlink3.mk"
BUILDLINK_API_DEPENDS.librsvg+=	librsvg>=2.42.2		# for introspection
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
