# $NetBSD: Makefile,v 1.2 2008/05/24 06:14:00 obache Exp $
#

DISTNAME=	exempi-2.0.0
CATEGORIES=	devel graphics
MASTER_SITES=	http://libopenraw.freedesktop.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libopenraw.freedesktop.org/wiki/Exempi
COMMENT=	XMP library

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	exempi/exempi-2.0.pc.in

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
