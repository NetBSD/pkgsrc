# $NetBSD: Makefile,v 1.4 2004/02/25 18:50:03 minskim Exp $
#

DISTNAME=	fuse-utils-0.6.2
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fuse-emulator/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://fuse-emulator.sourceforge.net/
COMMENT=	ZX Spectrum Emulator utilities

USE_BUILDLINK3=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

.include "../../emulators/libspectrum/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
