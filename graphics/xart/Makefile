# $NetBSD: Makefile,v 1.15 2000/08/23 23:14:27 tron Exp $
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
DEPENDS+=	png>=1.0.6:../../graphics/png

USE_IMAKE=      YES
USE_XPM=	YES

WRKSRC=		${WRKDIR}/19980415

post-extract:
	${FIND} ${WRKSRC} -type d -print | xargs ${CHMOD} 755
	${FIND} ${WRKSRC} -type f -print | xargs ${CHMOD} 644

.include "../../mk/bsd.pkg.mk"
