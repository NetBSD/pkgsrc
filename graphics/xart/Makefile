# $NetBSD: Makefile,v 1.1 1998/04/21 00:46:57 hubertf Exp $
#

DISTNAME=       xart19980415
PKGNAME=	xart-19980415
CATEGORIES=	graphics x11
MASTER_SITES=	http://www.cqi.com/~humbubba/linux/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org

LIB_DEPENDS=    jpeg.7.:${PORTSDIR}/graphics/jpeg \
                tiff.3.:${PORTSDIR}/graphics/tiff \
                Xpm.4.:${PORTSDIR}/graphics/xpm   \
                png.0.:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/19980415
USE_IMAKE=      yes

post-extract:
	find ${WRKSRC} -type d -print | xargs chmod 755
	find ${WRKSRC} -type f -print | xargs chmod 644

.include "../../mk/bsd.pkg.mk"
