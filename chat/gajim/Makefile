# $NetBSD: Makefile,v 1.34 2017/04/08 18:08:53 riastradh Exp $

DISTNAME=	gajim-0.15
PKGREVISION=	16
CATEGORIES=	chat python
MASTER_SITES=	http://www.gajim.org/downloads/0.15/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	vsevolod@highsecure.ru
HOMEPAGE=	http://www.gajim.org/
COMMENT=	Jabber client written in PyGTK
LICENSE=	gnu-gpl-v3

DEPENDS=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
DEPENDS=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-gtk2

.include "options.mk"

USE_TOOLS+=	gmake intltool pkg-config msgfmt
GNU_CONFIGURE=	yes

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
