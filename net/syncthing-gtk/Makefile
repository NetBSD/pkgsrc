# $NetBSD: Makefile,v 1.30 2022/06/30 11:18:44 nia Exp $

DISTNAME=	syncthing-gtk-0.9.4.4
PKGREVISION=	6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=kozec/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/syncthing/syncthing-gtk
COMMENT=	GTK3 & Python based GUI for Syncthing
LICENSE=	gnu-gpl-v2

DEPENDS+=	syncthing>=0.13.0:../../net/syncthing
DEPENDS+=	glib-networking-[0-9]*:../../net/glib-networking # GIO GnuTLS support
DEPENDS+=	psmisc-[0-9]*:../../sysutils/psmisc # for killall
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject32

PYTHON_VERSIONS_ACCEPTED=	27

EGG_NAME=	${DISTNAME:S/0/v0/:S/-/_/}

REPLACE_PYTHON+=		*.py scripts/*.py syncthing_gtk/*.py

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

SUBST_CLASSES+=		int
SUBST_STAGE.int=	pre-build
SUBST_MESSAGE.int=	Replacing hard-coded python interpreter
SUBST_FILES.int=	syncthing_gtk/tools.py
SUBST_SED.int=		-e 's|/usr/bin/env python2|${PYTHONBIN}|'

BUILDLINK_API_DEPENDS.libnotify+=	libnotify>=0.7.8
.include "../../sysutils/libnotify/buildlink3.mk"
BUILDLINK_API_DEPENDS.librsvg+=	librsvg>=2.42.2		# for introspection
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
