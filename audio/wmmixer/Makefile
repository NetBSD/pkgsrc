# $NetBSD: Makefile,v 1.7 2004/01/20 12:07:43 agc Exp $
#

DISTNAME=	wmmixer-1.0-beta1
PKGNAME=	wmmixer-1.0
CATEGORIES=	audio
MASTER_SITES=	http://www.geocities.com/SiliconValley/Vista/2471/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pr@alles.prima.de
HOMEPAGE=	http://www.geocities.com/SiliconValley/Vista/2471/
COMMENT=	Mixer designed for WindowMaker (dockapp)

WRKSRC=			${WRKDIR}/wmmixer
USE_BUILDLINK2=		YES
USE_IMAKE=		YES
NO_INSTALL_MANPAGES=	YES

pre-build:
	${TOUCH} ${WRKSRC}/wmmixer.man

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
