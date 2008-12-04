# $NetBSD: Makefile,v 1.27 2008/12/04 07:40:20 adam Exp $

DISTNAME=	fuse-0.10.0
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fuse-emulator/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://fuse-emulator.sourceforge.net/
COMMENT=	ZX Spectrum Emulator

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		perl pkg-config
GNU_CONFIGURE=		yes
LIBS+=	${LIBOSSAUDIO}

.include "options.mk"

.include "../../emulators/libspectrum/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
