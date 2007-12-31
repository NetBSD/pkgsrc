# $NetBSD: Makefile,v 1.2 2007/12/31 23:38:29 bjs Exp $
#

DISTNAME=	psftools-1.0.6-rc1
PKGNAME=	${DISTNAME:S/-rc1//}
CATEGORIES=	sysutils fonts
MASTER_SITES=	http://www.seasip.info/Unix/PSF/

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://www.seasip.info/Unix/PSF/index.html
COMMENT=	Tools for manipulating fixed-width, [typically] console fonts

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

.include "../../mk/bsd.pkg.mk"
