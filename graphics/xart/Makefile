# $NetBSD: Makefile,v 1.19 2001/05/22 09:32:22 wiz Exp $
#

DISTNAME=       xart19980415
PKGNAME=	xart-19980415
CATEGORIES=	graphics x11
MASTER_SITES=	http://www.cqi.com/~humbubba/linux/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cqi.com/~humbubba/linux.html
COMMENT=	Paint program (enhanced xpaint)

DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	tiff-*:../../graphics/tiff
DEPENDS+=	png>=1.0.11:../../graphics/png

USE_IMAKE=      YES
USE_XPM=	YES

WRKSRC=		${WRKDIR}/19980415

post-extract:
	${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755
	${FIND} ${WRKSRC} -type f -print | ${XARGS} ${CHMOD} 644

.include "../../mk/bsd.pkg.mk"
