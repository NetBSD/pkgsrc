# $NetBSD: Makefile,v 1.71 2026/08/08 06:40:46 adam Exp $

DISTNAME=	fuse-1.9.1
PKGNAME=	${DISTNAME:S/fuse/fuse-emulator/}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fuse-emulator/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://fuse-emulator.sourceforge.net/
COMMENT=	ZX Spectrum Emulator
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake perl pkg-config
GNU_CONFIGURE=	yes

.include "options.mk"

.include "../../devel/SDL2/buildlink3.mk"
.include "../../emulators/libspectrum/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
