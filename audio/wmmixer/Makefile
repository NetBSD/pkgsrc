# $NetBSD: Makefile,v 1.5 2003/03/29 12:40:09 jmmv Exp $
#

DISTNAME=	wmmixer-1.0-beta1
PKGNAME=	wmmixer-1.0
WRKSRC=		${WRKDIR}/wmmixer
CATEGORIES=	audio
MASTER_SITES=	http://www.geocities.com/SiliconValley/Vista/2471/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pr@alles.prima.de
HOMEPAGE=	http://www.geocities.com/SiliconValley/Vista/2471/
COMMENT=	mixer designed for WindowMaker (dockapp)

USE_BUILDLINK2=		YES
USE_IMAKE=		YES
NO_INSTALL_MANPAGES=	YES

pre-build:
	${TOUCH} ${WRKSRC}/wmmixer.man

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
