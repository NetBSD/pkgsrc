# $NetBSD: Makefile,v 1.19 2026/08/08 06:41:38 adam Exp $

DISTNAME=	fuse-utils-1.4.6
PKGNAME=	${DISTNAME:S/fuse/fuse-emulator/}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fuse-emulator/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://fuse-emulator.sourceforge.net/
COMMENT=	ZX Spectrum Emulator utilities
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes

.include "../../emulators/libspectrum/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
