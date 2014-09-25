# $NetBSD: Makefile,v 1.61 2014/09/25 10:34:45 jperkin Exp $
#

DISTNAME=	xart19980415
PKGNAME=	xart-19980415
PKGREVISION=	19
CATEGORIES=	graphics x11
MASTER_SITES=	http://linux01.gwdg.de/~rhohen/linux/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://linux01.gwdg.de/~rhohen/linux.html
COMMENT=	Paint program (enhanced xpaint)
# quite like isc, but copyright needs to mention in documentation as well
# see the bottom of the included "Help.txt" file
#LICENSE=	isc

WRKSRC=		${WRKDIR}/19980415
USE_IMAKE=	YES

post-extract:
	${CHMOD} 755 ${WRKSRC} ${WRKSRC}/{Doc,bitmaps,rw}
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} 644 {} \;

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
