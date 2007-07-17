# $NetBSD: Makefile,v 1.1.1.1 2007/07/17 19:03:16 drochner Exp $
#

DISTNAME=	orca-2.18.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/orca/2.18/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/Orca
COMMENT=	Screen reader

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool pkg-config gmake
USE_DIRS+=	xdg-1.1

PYTHON_VERSIONS_ACCEPTED= 24
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}
PY_PATCHPLIST=	yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../devel/at-spi/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../net/py-ORBit/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
