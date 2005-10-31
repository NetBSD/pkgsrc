# $NetBSD: Makefile,v 1.10 2005/10/31 16:37:24 tv Exp $
#

DISTNAME=	wmmixer-1.0-beta1
PKGNAME=	wmmixer-1.0
CATEGORIES=	audio
MASTER_SITES=	http://www.geocities.com/SiliconValley/Vista/2471/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pr@alles.prima.de
HOMEPAGE=	http://www.geocities.com/SiliconValley/Vista/2471/
COMMENT=	Mixer designed for WindowMaker (dockapp)

NOT_FOR_PLATFORM=	Interix-*-*

WRKSRC=			${WRKDIR}/wmmixer
USE_IMAKE=		YES
NO_INSTALL_MANPAGES=	YES

pre-build:
	${TOUCH} ${WRKSRC}/wmmixer.man

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
