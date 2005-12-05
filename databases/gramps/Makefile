# $NetBSD: Makefile,v 1.16 2005/12/05 20:49:57 rillig Exp $
#

DISTNAME=		gramps-1.0.11
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

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}
# i18n support with other python versions appears to not work
PYTHON_VERSION_REQD=	23

MESSAGE_SUBST+=		PYPKGPREFIX=${PYPKGPREFIX}

.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
