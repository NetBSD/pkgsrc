# $NetBSD: Makefile,v 1.2 2004/02/13 13:42:15 adam Exp $
#

DISTNAME=	fuse-utils-0.6.2
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
