# $NetBSD: Makefile,v 1.61 2012/10/02 21:25:18 asau Exp $
#

DISTNAME=		gramps-1.0.11
PKGREVISION=		30
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gramps/}

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://gramps-project.org/
COMMENT=	Genealogical Research and Analysis Management Programming System

MAKE_JOBS_SAFE=		no

DEPENDS+=	yelp>=2.2:../../misc/yelp

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		msgconv msgfmt pkg-config

CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}
PYTHON_VERSIONS_ACCEPTED=	25

MESSAGE_SUBST+=		PYPKGPREFIX=${PYPKGPREFIX}

.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
