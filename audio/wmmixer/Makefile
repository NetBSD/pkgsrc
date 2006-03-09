# $NetBSD: Makefile,v 1.12 2006/03/09 21:04:42 jlam Exp $
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

NOT_FOR_PLATFORM=	Interix-*-*

WRKSRC=			${WRKDIR}/wmmixer
USE_IMAKE=		YES
NO_INSTALL_MANPAGES=	YES

pre-build:
	${TOUCH} ${WRKSRC}/wmmixer.man

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
