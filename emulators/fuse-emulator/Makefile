# $NetBSD: Makefile,v 1.75 2026/09/29 06:04:53 wiz Exp $

DISTNAME=	fuse-1.9.2
PKGNAME=	${DISTNAME:S/fuse/fuse-emulator/}
PKGREVISION=	2
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
