# $NetBSD: Makefile,v 1.17 2010/02/10 19:17:39 joerg Exp $

DISTNAME=	gpsd-2.90
PKGREVISION=	2
CATEGORIES=	geography
MASTER_SITES=	http://download.berlios.de/gpsd/

MAINTAINER=	tsarna@NetBSD.org
# MAINTAINER+=	gdt@NetBSD.org
HOMEPAGE=	http://gpsd.berlios.de/
COMMENT=	GPS information daemon

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}
PY_PATCHPLIST=	yes

USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_NCURSES=	yes

INSTALLATION_DIRS=	sbin

.include "../../devel/ncurses/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
