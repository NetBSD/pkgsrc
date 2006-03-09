# $NetBSD: Makefile,v 1.20 2006/03/09 21:04:43 jlam Exp $

DISTNAME=	fuse-0.7.0
PKGREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fuse-emulator/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://fuse-emulator.sourceforge.net/
COMMENT=	ZX Spectrum Emulator

USE_TOOLS+=		perl pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gtk2
LIBS+=	${LIBOSSAUDIO}

.include "../../emulators/libspectrum/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
