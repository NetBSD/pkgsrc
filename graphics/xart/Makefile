# $NetBSD: Makefile,v 1.32 2004/01/20 12:18:17 agc Exp $
#

DISTNAME=       xart19980415
PKGNAME=	xart-19980415
PKGREVISION=	4
CATEGORIES=	graphics x11
MASTER_SITES=	http://linux01.gwdg.de/~rhohen/linux/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://linux01.gwdg.de/~rhohen/linux.html
COMMENT=	Paint program (enhanced xpaint)

WRKSRC=		${WRKDIR}/19980415
USE_BUILDLINK2=	YES
USE_IMAKE=      YES

post-extract:
	${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755
	${FIND} ${WRKSRC} -type f -print | ${XARGS} ${CHMOD} 644

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
