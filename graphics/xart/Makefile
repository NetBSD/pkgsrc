# $NetBSD: Makefile,v 1.50 2010/06/13 22:44:46 wiz Exp $
#

DISTNAME=	xart19980415
PKGNAME=	xart-19980415
PKGREVISION=	14
CATEGORIES=	graphics x11
MASTER_SITES=	http://linux01.gwdg.de/~rhohen/linux/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://linux01.gwdg.de/~rhohen/linux.html
COMMENT=	Paint program (enhanced xpaint)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/19980415
USE_IMAKE=	YES

post-extract:
	cd ${WRKDIR} && find * -type d -exec chmod 755 "{}" ";"
	cd ${WRKDIR} && find * -type f -print | xargs chmod 644

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
