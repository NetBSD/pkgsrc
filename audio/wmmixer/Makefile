# $NetBSD: Makefile,v 1.3 2001/02/16 13:30:51 wiz Exp $
#

DISTNAME=	wmmixer-1.0-beta1
PKGNAME=	wmmixer-1.0
CATEGORIES=	audio
MASTER_SITES=	http://www.geocities.com/SiliconValley/Vista/2471/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pr@alles.prima.de
HOMEPAGE=	http://www.geocities.com/SiliconValley/Vista/2471/
COMMENT=	mixer designed for WindowMaker (dockapp)

WRKSRC=		${WRKDIR}/wmmixer

USE_IMAKE=	YES
USE_XPM=	YES
NO_INSTALL_MANPAGES= YES

pre-build:
	${TOUCH} ${WRKSRC}/wmmixer.man

.include "../../mk/bsd.pkg.mk"
