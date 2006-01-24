# $NetBSD: Makefile,v 1.10 2006/01/24 07:31:59 wiz Exp $
#

DISTNAME=		gramps-2.0.8
PKGREVISION=		3
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gramps/}

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://gramps.sourceforge.net/
COMMENT=	Genealogical Research and Analysis Management Programming System

DEPENDS+=	yelp>=2.2:../../misc/yelp

.if !exists(/usr/bin/msgconv)
BUILD_DEPENDS+=	gettext>=0.10.35nb1:../../devel/gettext
.endif
#BUILD_USES_MSGFMT=	yes

USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
# disable gconf schema and mime type processing
CONFIGURE_ARGS+=	--disable-mime-install --enable-packager-mode

CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}
# i18n support with other python versions appears to not work
PYTHON_VERSIONS_ACCEPTED=	24 23

MESSAGE_SUBST+=		PYPKGPREFIX=${PYPKGPREFIX}
GCONF2_SCHEMAS+=	gramps.schemas

.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../databases/py-bsddb3/buildlink3.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../mk/bsd.pkg.mk"
