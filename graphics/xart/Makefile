# $NetBSD: Makefile,v 1.14 2000/03/21 22:40:55 tron Exp $
#

DISTNAME=       xart19980415
PKGNAME=	xart-19980415
CATEGORIES=	graphics x11
MASTER_SITES=	http://www.cqi.com/~humbubba/linux/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cqi.com/~humbubba/linux.html

DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	tiff-*:../../graphics/tiff
DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	png>=1.0.6:../../graphics/png

WRKSRC=		${WRKDIR}/19980415
USE_IMAKE=      yes

post-extract:
	${FIND} ${WRKSRC} -type d -print | xargs ${CHMOD} 755
	${FIND} ${WRKSRC} -type f -print | xargs ${CHMOD} 644

.include "../../mk/bsd.pkg.mk"
