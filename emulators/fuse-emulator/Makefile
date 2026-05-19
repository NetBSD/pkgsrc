# $NetBSD: Makefile,v 1.68 2026/05/19 12:58:01 adam Exp $

DISTNAME=	fuse-1.8.0
PKGNAME=	${DISTNAME:S/fuse/fuse-emulator/}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fuse-emulator/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://fuse-emulator.sourceforge.net/
COMMENT=	ZX Spectrum Emulator
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake perl pkg-config
GNU_CONFIGURE=	yes

CPPFLAGS+=	-DDEVOSSAUDIO=\"${DEVOSSAUDIO}\"
LIBS+=		${LIBOSSAUDIO}

.include "options.mk"

.include "../../emulators/libspectrum/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
