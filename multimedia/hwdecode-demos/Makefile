# $NetBSD: Makefile,v 1.4 2012/10/02 17:11:41 tron Exp $
#

DISTNAME=	hwdecode-demos-0.9.4
PKGREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	http://www.splitted-desktop.com/~gbeauchesne/hwdecode-demos/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.splitted-desktop.com/~gbeauchesne/
COMMENT=	Standalone programs showing off various HW acceleration APIs
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LIBTOOL=	yes

.include "../../graphics/cairo/buildlink3.mk"
.include "../../multimedia/libva/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
