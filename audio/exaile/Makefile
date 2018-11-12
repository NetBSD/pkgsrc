# $NetBSD: Makefile,v 1.59 2018/11/12 03:51:40 ryoon Exp $

DISTNAME=	exaile_0.2.14
PKGNAME=	${DISTNAME:S/_/-/1}
PKGREVISION=	37
CATEGORIES=	audio
MASTER_SITES=	http://www.exaile.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.exaile.org/
COMMENT=	Music player
LICENSE=	gnu-gpl-v2 # or later

DEPENDS+=	${PYPKGPREFIX}-mutagen-[0-9]*:../../audio/py-mutagen
DEPENDS+=	${PYPKGPREFIX}-notify-python-[0-9]*:../../sysutils/py-notify-python

WRKSRC=		${WRKDIR}/exaile-0.2.14

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config gmake intltool msgfmt

REPLACE_PYTHON=	exaile.py
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-sqlite2, py-gtk2, py-gstreamer0.10

MAKE_ENV+=	PYTHONBIN=${PYTHONBIN}
MAKE_FLAGS+=	PKGLOCALEDIR=${PKGLOCALEDIR}

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/python/application.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../multimedia/py-gstreamer0.10/buildlink3.mk"
.include "../../textproc/py-elementtree/buildlink3.mk"
.include "../../databases/py-sqlite2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
