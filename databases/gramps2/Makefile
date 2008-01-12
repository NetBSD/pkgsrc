# $NetBSD: Makefile,v 1.33 2008/01/12 11:36:31 adam Exp $
#

DISTNAME=		gramps-2.2.9
PKGREVISION=		1
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gramps/}

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://gramps-project.org/
COMMENT=	Genealogical Research and Analysis Management Programming System

PKG_DESTDIR_SUPPORT=	user-destdir

USE_DIRS+=		xdg-1.1
USE_TOOLS+=		msgfmt pkg-config intltool msgconv
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
# disable gconf schema and mime type processing
CONFIGURE_ARGS+=	--disable-mime-install --enable-packager-mode

CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}
MAKE_JOBS_SAFE=		no
# i18n support with other python versions appears to not work
PYTHON_VERSIONS_ACCEPTED=	24

MESSAGE_SUBST+=		PYPKGPREFIX=${PYPKGPREFIX}
GCONF_SCHEMAS+=	gramps.schemas

.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../databases/py-bsddb3/buildlink3.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
