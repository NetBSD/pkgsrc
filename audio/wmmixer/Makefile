# $NetBSD: Makefile,v 1.19 2016/04/20 12:10:33 nros Exp $
#

DISTNAME=	wmmixer-1.0-beta1
PKGNAME=	wmmixer-1.0
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.geocities.com/SiliconValley/Vista/2471/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pr@alles.prima.de
HOMEPAGE=	http://www.geocities.com/SiliconValley/Vista/2471/
COMMENT=	Mixer designed for WindowMaker (dockapp)
LICENSE=	gnu-gpl-v2

NOT_FOR_PLATFORM=	Interix-*-*

WRKSRC=			${WRKDIR}/wmmixer
USE_IMAKE=		YES
USE_LANGUAGES=		c c++
NO_INSTALL_MANPAGES=	YES

pre-build:
	${TOUCH} ${WRKSRC}/wmmixer.man

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
