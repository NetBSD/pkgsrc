# $NetBSD: Makefile,v 1.8 1998/08/20 15:17:02 tsarna Exp $
#

DISTNAME=       xart19980415
PKGNAME=	xart-19980415
CATEGORIES=	graphics x11
MASTER_SITES=	http://www.cqi.com/~humbubba/linux/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cqi.com/~humbubba/linux.html

DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	tiff-3.4:../../graphics/tiff
DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	png-1.0.2:../../graphics/png

WRKSRC=		${WRKDIR}/19980415
USE_IMAKE=      yes

post-extract:
	find ${WRKSRC} -type d -print | xargs chmod 755
	find ${WRKSRC} -type f -print | xargs chmod 644

.include "../../mk/bsd.pkg.mk"
