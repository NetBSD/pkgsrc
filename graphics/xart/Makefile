# $NetBSD: Makefile,v 1.23 2001/08/22 14:53:48 jlam Exp $
#

DISTNAME=       xart19980415
PKGNAME=	xart-19980415nb1
CATEGORIES=	graphics x11
MASTER_SITES=	http://linux01.gwdg.de/~rhohen/linux/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://linux01.gwdg.de/~rhohen/linux.html
COMMENT=	Paint program (enhanced xpaint)

USE_BUILDLINK_ONLY=YES
USE_IMAKE=      YES

WRKSRC=		${WRKDIR}/19980415

post-extract:
	${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755
	${FIND} ${WRKSRC} -type f -print | ${XARGS} ${CHMOD} 644

.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
