# $NetBSD: Makefile,v 1.5 2012/10/08 09:21:04 asau Exp $
#

DISTNAME=	hwdecode-demos-0.9.4
PKGREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	http://www.splitted-desktop.com/~gbeauchesne/hwdecode-demos/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.splitted-desktop.com/~gbeauchesne/
COMMENT=	Standalone programs showing off various HW acceleration APIs
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LIBTOOL=	yes

.include "../../graphics/cairo/buildlink3.mk"
.include "../../multimedia/libva/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
