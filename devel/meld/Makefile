# $NetBSD: Makefile,v 1.101 2020/04/20 07:04:00 wiz Exp $

DISTNAME=		meld-3.21.0
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/meld/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		https://meldmerge.org/
COMMENT=		Visual diff and merge tool (GTK3 version)
LICENSE=		gnu-gpl-v2

BUILD_DEPENDS+=		itstool-[0-9]*:../../textproc/itstool
BUILD_DEPENDS+=		${PYPKGPREFIX}-distro-[0-9]*:../../devel/py-distro
DEPENDS+=		${PYPKGPREFIX}-gobject3>=3.8:../../devel/py-gobject3
DEPENDS+=		gsettings-desktop-schemas-[0-9]*:../../sysutils/gsettings-desktop-schemas
DEPENDS+=		dconf-[0-9]*:../../devel/dconf

USE_TOOLS+=		intltool msgfmt

PYTHON_VERSIONS_INCOMPATIBLE=	27 # not supported any longer

SUBST_CLASSES+=		man
SUBST_FILES.man=	setup.py
SUBST_SED.man+=		-e "s,share/man/man1,${PKGMANDIR}/man1,"
SUBST_STAGE.man=	pre-build
SUBST_MESSAGE.man=	Fixing man page installation path.

.include "../../graphics/adwaita-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/python/distutils.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.36.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.20
.include "../../x11/gtk3/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtksourceview3+=	gtksourceview3>=3.20
.include "../../x11/gtksourceview3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
