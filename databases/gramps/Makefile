# $NetBSD: Makefile,v 1.7 2004/10/03 00:13:18 tv Exp $
#

DISTNAME=		gramps-1.0.6
PKGREVISION=	1
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

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		PYTHON=${PYTHONBIN}
# i18n support with other python versions appears to not work
PYTHON_VERSION_REQD=	23pth

MESSAGE_SUBST+=		PYPKGPREFIX=${PYPKGPREFIX}

.include "../../textproc/scrollkeeper/omf.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
