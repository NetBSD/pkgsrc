# $NetBSD: Makefile,v 1.41 2006/08/09 17:13:58 darcy Exp $
#

DISTNAME=	xart19980415
PKGNAME=	xart-19980415
PKGREVISION=	10
CATEGORIES=	graphics x11
MASTER_SITES=	http://linux01.gwdg.de/~rhohen/linux/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://linux01.gwdg.de/~rhohen/linux.html
COMMENT=	Paint program (enhanced xpaint)

WRKSRC=		${WRKDIR}/19980415
USE_IMAKE=	YES

post-extract:
	${FIND} ${WRKSRC} -type d -exec ${CHMOD} 755 {} \;
	${FIND} ${WRKSRC} -type f -print | ${XARGS} ${CHMOD} 644

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
