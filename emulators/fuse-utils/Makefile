# $NetBSD: Makefile,v 1.3 2004/02/25 16:09:46 minskim Exp $
#

DISTNAME=	fuse-utils-0.6.2
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fuse-emulator/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://fuse-emulator.sourceforge.net/
COMMENT=	ZX Spectrum Emulator utilities

USE_BUILDLINK2=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

.include "../../emulators/libspectrum/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
