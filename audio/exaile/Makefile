# $NetBSD: Makefile,v 1.5 2007/09/21 13:03:26 wiz Exp $
#

DISTNAME=	exaile_0.2.10
PKGNAME=	exaile-0.2.10
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.exaile.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.exaile.org/
COMMENT=	Music player

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config gmake intltool
USE_DIRS+=		xdg-1.1

PYTHON_PATCH_SCRIPTS=	exaile.py
MAKE_ENV+=	PYTHONBIN=${PYTHONBIN}

EX=	${PREFIX}/bin/exaile
post-install:
	${ECHO} "#!/bin/sh" > ${EX}
	${ECHO} exec "${PYTHONBIN} ${PREFIX}/share/exaile/exaile.py" >> ${EX}
	chmod 755 ${EX}

.include "../../lang/python/application.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../audio/py-mutagen/buildlink3.mk"
.include "../../multimedia/py-gstreamer0.10/buildlink3.mk"
.include "../../textproc/py-elementtree/buildlink3.mk"
.include "../../databases/py-sqlite2/buildlink3.mk"
.include "../../sysutils/py-notify/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
