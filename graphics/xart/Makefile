# $NetBSD: Makefile,v 1.35 2004/12/28 23:18:19 reed Exp $
#

DISTNAME=       xart19980415
PKGNAME=	xart-19980415
PKGREVISION=	6
CATEGORIES=	graphics x11
MASTER_SITES=	http://linux01.gwdg.de/~rhohen/linux/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://linux01.gwdg.de/~rhohen/linux.html
COMMENT=	Paint program (enhanced xpaint)

WRKSRC=		${WRKDIR}/19980415
USE_BUILDLINK3=	YES
USE_IMAKE=      YES

post-extract:
	${FIND} ${WRKSRC} -type d -exec ${CHMOD} 755 {} \;
	${FIND} ${WRKSRC} -type f -print | ${XARGS} ${CHMOD} 644

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
