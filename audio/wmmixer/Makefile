# $NetBSD: Makefile,v 1.2 2001/01/19 12:45:13 wiz Exp $
#

DISTNAME=	wmmixer-1.0-beta1
PKGNAME=	wmmixer-1.0
CATEGORIES=	audio
MASTER_SITES=	http://www.geocities.com/SiliconValley/Vista/2471/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pr@alles.prima.de
HOMEPAGE=	http://www.geocities.com/SiliconValley/Vista/2471/

WRKSRC=		${WRKDIR}/wmmixer

USE_IMAKE=	YES
USE_XPM=	YES
NO_INSTALL_MANPAGES= YES

pre-build:
	${TOUCH} ${WRKSRC}/wmmixer.man

.include "../../mk/bsd.pkg.mk"
