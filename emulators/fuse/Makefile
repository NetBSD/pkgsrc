# $NetBSD: Makefile,v 1.49 2012/10/08 23:01:31 adam Exp $

DISTNAME=	fuse-1.0.0.1a
PKGREVISION=	9
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fuse-emulator/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://fuse-emulator.sourceforge.net/
COMMENT=	ZX Spectrum Emulator
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		perl pkg-config
GNU_CONFIGURE=		yes

CPPFLAGS+=		-DDEVOSSAUDIO=\"${DEVOSSAUDIO}\"
LIBS+=			${LIBOSSAUDIO}

.include "options.mk"

.include "../../emulators/libspectrum/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
