# $NetBSD: Makefile,v 1.2 2011/01/13 13:37:12 wiz Exp $
#

DISTNAME=	gajim-0.14.1
PKGREVISION=	1
CATEGORIES=	chat python
MASTER_SITES=	http://www.gajim.org/downloads/0.14/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	vsevolod@highsecure.ru
HOMEPAGE=	http://www.gajim.org/
COMMENT=	Jabber client written in PyGTK
LICENSE=	gnu-gpl-v3

DEPENDS=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
DEPENDS=	${PYPKGPREFIX}-dbus-[0-9]*:../../sysutils/py-dbus

PKG_DESTDIR_SUPPORT=	user-destdir

.include "options.mk"

USE_TOOLS+=	gmake intltool pkg-config
GNU_CONFIGURE=	yes

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../databases/py-sqlite2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
